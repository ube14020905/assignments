#include <iostream>
#include <winsock2.h>
#include <thread>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

void HandleClient(SOCKET client)
{
    char buffer[1024];
    int bytesRead;

    do
    {
        bytesRead = recv(client, buffer, sizeof(buffer), 0);
        if (bytesRead > 0)
        {
            buffer[bytesRead] = '\0';
            cout << "Received message from client: " << buffer << endl;

            if (strcmp(buffer, "bye") == 0 || strcmp(buffer, "BYE") == 0 || strcmp(buffer, "Bye") == 0 || strcmp(buffer, "Bye!!") == 0)
            {
                break;
            }

            const char *response;
            cout << "Enter response for client: ";
            cin.getline(buffer, sizeof(buffer));
            response = buffer;

            send(client, response, strlen(response), 0);

            if (strcmp(response, "bye") == 0 || strcmp(response, "BYE") == 0 || strcmp(response, "Bye") == 0 || strcmp(response, "bye!!!") == 0)
            {
                break;
            }
        }
    } while (bytesRead > 0);

    closesocket(client);
}

int main()
{
    WSADATA data;
    if (WSAStartup(MAKEWORD(2, 2), &data) != 0)
    {
        cerr << "Failed to initialize Winsock" << endl;
        return 1;
    }

    SOCKET server = socket(AF_INET, SOCK_STREAM, 0);
    if (server == INVALID_SOCKET)
    {
        cerr << "Failed to create socket" << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(12345);

    if (bind(server, (sockaddr *)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
    {
        cerr << "Bind failed with error: " << WSAGetLastError() << endl;
        closesocket(server);
        WSACleanup();
        return 1;
    }

    if (listen(server, SOMAXCONN) == SOCKET_ERROR)
    {
        cerr << "Listen failed with error: " << WSAGetLastError() << endl;
        closesocket(server);
        WSACleanup();
        return 1;
    }

    cout << "Server listening on port 12345.." << endl;

    vector<thread> threads;

    while (true)
    {
        SOCKET client;
        sockaddr_in clientAddress;
        int clientAddressSize = sizeof(clientAddress);

        client = accept(server, (sockaddr *)&clientAddress, &clientAddressSize);
        if (client == INVALID_SOCKET)
        {
            cerr << "Accept failed with error: " << WSAGetLastError() << endl;
            closesocket(server);
            WSACleanup();
            return 1;
        }

        threads.emplace_back(HandleClient, client);
    }

    for (auto &th : threads)
    {
        th.join();
    }

    closesocket(server);
    WSACleanup();

    return 0;
}
