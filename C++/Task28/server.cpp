#include<iostream>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib")
using namespace std;

int main(){
	WSADATA WSAdata;
	if(WSAStartup(MAKEWORD(2,2),&WSAdata) !=0){
		cerr<<"Failed to Initialize winsock!!!"<<endl;
		return 1;
	}
	SOCKET server=socket(AF_INET,SOCK_STREAM,0);
	if(server == SOCKET_ERROR){
		cerr<<"Failed to create Server Socket!!!"<<endl;
		WSACleanup();
		return 1;
	}
	sockaddr_in socketAddress;
	socketAddress.sin_family = AF_INET;
	socketAddress.sin_addr.s_addr = INADDR_ANY;
	socketAddress.sin_port = htons(12345);

	if(bind(server,(sockaddr*)&serverAddress,sizeof(socketAddress)) == SOCKET_ERROR){
		cerr<<"Failed to SOCKET BIND!!!"<<endl;
		closesocket(server);
		WSACleanup();
		return 1;
	}

	if(listen(server,SOMAXCONN) == SOCKET_ERROR){
		cerr<<"Failed to Start Listening Mode!!! "<<WSAGetLastError()<<endl;
		closesocket(server);
		WSACleanup();
		return 1;
	}
	cout<<"Listening at port Number 12345....!"<<endl;
	SOCKET client;
	sockaddr_in clientAddr;
	int clientAddrSize=sizeof(clientAddr);
	while(true){
		client=accept(server,(sockaddr*)&clinetAddr,clientAddrSize,0);
		if(client == INVALID_SOCKET){
			cerr<<"Falied to connect with client"<<endl;
			closesocket(server);
			WSACleanup();
			return 1;
		}
		cout<<"Connection accepted from "<<inet_ntoa(clientAddr.sin_addr)<<" : "<<ntohs(clientAddr.sin_port)<<endl;
        


    }
}
