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

    SOCKET server = socket(AF_INET, SOCK_DGRAM, 0);
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

    cout << "Server listening on port 12345.." << endl;

    char buffer[1024];

    do
    {
        sockaddr_in clientAddress;
        int clientAddressSize = sizeof(clientAddress);

        int bytesRead = recvfrom(server, buffer, sizeof(buffer), 0, (sockaddr *)&clientAddress, &clientAddressSize);
        if (bytesRead > 0)
        {
            buffer[bytesRead] = '\0';
            cout << "Received message from client " << inet_ntoa(clientAddress.sin_addr) << ":" << ntohs(clientAddress.sin_port) << ": " << buffer << endl;

            if (strcmp(buffer, "bye") == 0 || strcmp(buffer, "BYE") == 0 || strcmp(buffer, "Bye") == 0 || strcmp(buffer, "Bye!!") == 0)
            {
                break;
            }

            const char *response;
            cout << "Enter response for client: ";
            cin.getline(buffer, sizeof(buffer));
            response = buffer;

            sendto(server, response, strlen(response), 0, (sockaddr *)&clientAddress, sizeof(clientAddress));

            if (strcmp(response, "bye") == 0 || strcmp(response, "BYE") == 0 || strcmp(response, "Bye") == 0 || strcmp(response, "bye!!!") == 0)
            {
                break;
            }
        }

    } while (true);

    closesocket(server);
    WSACleanup();

    return 0;
}
