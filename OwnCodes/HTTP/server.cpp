#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")
using namespace std;
string getResponseHeader(int contentLength) {
    return "HTTP/1.1 200 OK\r\nContent-Length: " + std::to_string(contentLength) + "\r\n\r\n";
}

string get404Response() {
    return "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
}

void handleRequest(SOCKET clientSocket, const string& request) {
    string startString = "GET ";
    string endString = " HTTP/1.1\r\n";

    size_t start = request.find(startString);
    size_t end = request.find(endString);

    if (start != string::npos && end != string::npos) {
        string requested_resource = request.substr(start + startString.length(), end - start - startString.length());

        if (requested_resource == "/")
            requested_resource = "/home.html";

        ifstream file("." + requested_resource, ios::binary);
        
        if (file.is_open()) {
            ostringstream fileContent;
            fileContent << file.rdbuf();
            string response_content = fileContent.str();

            string response = getResponseHeader(response_content.size()) + response_content;

            send(clientSocket, response.c_str(), response.size(), 0);
        } else {
            string response = get404Response();
            send(clientSocket, response.c_str(), response.size(), 0);
        }
    }
}
int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "Failed to initialize Winsock" << endl;
        return 1;
    }

    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocket == INVALID_SOCKET) {
        cerr << "Failed to create socket: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(12345);

    if (bind(listenSocket, (sockaddr*)(&serverAddress), sizeof(serverAddress)) == SOCKET_ERROR) {
        cerr << "Failed to bind socket: " << WSAGetLastError() << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Failed to listen on socket: " << WSAGetLastError() << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    cout << "Server listening on port " << DEFAULT_PORT << endl;

    while (true) {
        SOCKET clientSocket = accept(listenSocket, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET) {
            cerr << "Failed to accept client connection: " << WSAGetLastError() << endl;
            closesocket(listenSocket);
            WSACleanup();
            return 1;
        }

        char buffer[4096];
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);

        if (bytesRead > 0) {
            string request(buffer, bytesRead);
            handleRequest(clientSocket, request);
        }

        closesocket(clientSocket);
    }

    closesocket(listenSocket);
    WSACleanup();

    return 0;
}