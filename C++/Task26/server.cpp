#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

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

    SOCKET client;
    sockaddr_in clientAddress;
    int clientAddressSize = sizeof(clientAddress);

    while (true)
    {
        client = accept(server, (sockaddr *)&clientAddress, &clientAddressSize);
        if (client == INVALID_SOCKET)
        {
            cerr << "Accept failed with error: " << WSAGetLastError() << endl;
            closesocket(server);
            WSACleanup();
            return 1;
        }

        cout << "Connection accepted from " << inet_ntoa(clientAddress.sin_addr) << ":" << ntohs(clientAddress.sin_port) << endl;

        char buffer[1024];
        int bytesRead;

        do
        {
            bytesRead = recv(client, buffer, sizeof(buffer), 0);
            if (bytesRead > 0)
            {
                buffer[bytesRead] = '\0';
                cout << "Received message from client: " << buffer << endl;
                if (buffer == "bye" || buffer == "BYE" || buffer == "Bye" || buffer == "Bye!!")
                {
                    break;
                }
                const char *response;
                cout << "Enter response for client: ";
                cin.getline(buffer, sizeof(buffer));
                response = buffer;
                send(client, response, strlen(response), 0);
                if (response == "bye" || response == "BYE" || response == "Bye" || response == "bye!!!")
                {
                    break;
                }
            }
        } while (bytesRead > 0);

        closesocket(client);
    }

    closesocket(server);
    WSACleanup();

    return 0;
}
