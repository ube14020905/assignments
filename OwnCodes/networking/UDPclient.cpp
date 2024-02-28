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

    SOCKET client = socket(AF_INET, SOCK_DGRAM, 0);
    if (client == INVALID_SOCKET)
    {
        cerr << "Failed to create socket" << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("182.156.8.98"); // Replace with the public IP of the server's network
    serverAddress.sin_port = htons(12345);

    char buffer[1024];

    do
    {
        const char *message;
        cout << "Enter message for server: ";
        cin.getline(buffer, sizeof(buffer));
        message = buffer;

        sendto(client, message, strlen(message), 0, (sockaddr *)&serverAddress, sizeof(serverAddress));

        if (strcmp(message, "bye") == 0 || strcmp(message, "BYE") == 0 || strcmp(message, "Bye") == 0 || strcmp(message, "Bye!!") == 0)
        {
            break;
        }

        int bytesRead = recvfrom(client, buffer, sizeof(buffer), 0, NULL, NULL);
        if (bytesRead > 0)
        {
            buffer[bytesRead] = '\0';
            cout << "Received response from server: " << buffer << endl;
        }

    } while (true);

    closesocket(client);
    WSACleanup();

    return 0;
}
