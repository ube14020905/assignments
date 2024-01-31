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

	SOCKET clients[FD_SETSIZE];
	fd_set readSet;
	FD_ZERO(&readSet);
	FD_SET(server, &readSet);
	int maxfd = server;

	while (true)
	{
		fd_set tmpSet = readSet;
		int activity = select(0, &tmpSet, nullptr, nullptr, nullptr);

		if (activity == SOCKET_ERROR)
		{
			cerr << "Select failed with error: " << WSAGetLastError() << endl;
			break;
		}

		if (FD_ISSET(server, &tmpSet))
		{
			SOCKET client = accept(server, nullptr, nullptr);
			if (client == INVALID_SOCKET)
			{
				cerr << "Accept failed with error: " << WSAGetLastError() << endl;
			}
			else
			{
				cout << "New connection established." << endl;
				FD_SET(client, &readSet);
				if (client > maxfd)
				{
					maxfd = client;
				}
			}
			FD_CLR(server, &tmpSet);
		}

		for (int i = 0; i <= maxfd; ++i)
		{
			if (FD_ISSET(i, &tmpSet))
			{
				char buffer[1024];
				int bytesRead = recv(i, buffer, sizeof(buffer), 0);

				if (bytesRead <= 0)
				{
					cout << "Client disconnected." << endl;
					closesocket(i);
					FD_CLR(i, &readSet);
				}
				else
				{
					buffer[bytesRead] = '\0';
					cout << "Received message from client " << i << ": " << buffer << endl;

					if (strcmp(buffer, "bye") == 0 || strcmp(buffer, "BYE") == 0 || strcmp(buffer, "Bye") == 0 || strcmp(buffer, "Bye!!") == 0)
					{
						cout << "Closing connection for client " << i << endl;
						closesocket(i);
						FD_CLR(i, &readSet);
					}
					else
					{
						for (int j = 0; j <= maxfd; ++j)
						{
							if (FD_ISSET(j, &readSet) && j != server && j != i)
							{
								send(j, buffer, strlen(buffer), 0);
							}
						}
					}
				}
			}
		}
	}

	closesocket(server);
	WSACleanup();

	return 0;
}
