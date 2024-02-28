#include <iostream>
#include <winsock2.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

const int DEFAULT_BUFLEN = 1024;

int main() {
    WSADATA data;
    if (WSAStartup(MAKEWORD(2, 2), &data) != 0) {
        cerr << "Failed to initialize Winsock" << endl;
        return 1;
    }

    SOCKET client = socket(AF_INET, SOCK_STREAM, 0);
    if (client == INVALID_SOCKET) {
        cerr << "Failed to create socket" << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(12345);

    if (connect(client, (sockaddr *)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        cerr << "Connection failed with error: " << WSAGetLastError() << endl;
        closesocket(client);
        WSACleanup();
        return 1;
    }

    char buffer[DEFAULT_BUFLEN];
    int bytesRead;

    do {
        const char *message;
        cout << "Enter message for server: ";
        cin.getline(buffer, sizeof(buffer));
        message = buffer;
        send(client, message, strlen(message), 0);
        if (strcmp(message, "bye") == 0 || strcmp(message, "BYE") == 0 || strcmp(message, "Bye") == 0 || strcmp(message, "Bye!!") == 0) {
            break;
        }

        bytesRead = recv(client, buffer, sizeof(buffer) - 1, 0);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            cout << "Received response from server: " << buffer << endl;
        }

    } while (bytesRead > 0);

    closesocket(client);
    WSACleanup();

    return 0;
}
