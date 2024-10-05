#include <iostream>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <tchar.h>
#include <thread>
#include <vector>


using namespace std;

#pragma comment(lib,"ws2_32.lib")

/*
	1.Intialize WinSock Library

	2.Create the socket

	3.get the ip and port 

	4.bind the ip/ port with the socket

	5.listen to the socket 

	6.accept the socket -> blocking calls (all in this video are blocking calls

	7.recv and send

	8.close the socket

	9. cleanup the winsock

*/

//end goal is to make client send and receive messages from each other 

bool Initialize() {

	WSADATA data;
	return WSAStartup(MAKEWORD(2, 2), &data) == 0;

}

void InteractWithClient(SOCKET clientSocket, vector<SOCKET> &clients) {
	//send/recv
	cout << "Client connected!" << endl;
	char buffer[4096];

	while (1) {
		int bytesrecvd = recv(clientSocket, buffer, sizeof(buffer), 0); //blocking call ?

		if (bytesrecvd <= 0) //why zero ?
		{
			cout << "Client Disconnected!" << endl;
		}

		string message(buffer, bytesrecvd);
		cout << "message from client :" << message << endl;

		for (auto client : clients) {
			if(client != clientSocket)
			{
				send(client, message.c_str(), message.length(), 0);
			}
			
		}
	}

	auto it = find(clients.begin(), clients.end(), clientSocket);
	if (it != clients.end())
	{
		clients.erase(it);
	}

	closesocket(clientSocket);

}

int main() {

	if (!Initialize())
	{
		cout << " Win Sock Initialization failed !" << endl;
	}


	cout << "Server Program" << endl;

	SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);

	if (listenSocket == INVALID_SOCKET)
	{
		cout << "Socket creation failed!" << endl;
		return 1;
	}

	//create address structure
	sockaddr_in serveraddr;
	int port = 12345;
	serveraddr.sin_family = AF_INET;
	//we cannot put integer to port directly , so little endian ya big endian mai convert karayla
	serveraddr.sin_port = htons(port); 

	//convert the ip address(0.0.0.0) put it inside sin_family in binary form
	if (InetPton(AF_INET, _T("0.0.0.0"), &serveraddr.sin_addr) != 1)
	{
		cout << "setting address structure failed!" << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	//bind the ip and port with the socket
	if (bind(listenSocket, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr)) == SOCKET_ERROR)
	{
		cout << "bind failed " << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	//listen
	if (listen(listenSocket, SOMAXCONN/*number clients it can take in a queue*/) == SOCKET_ERROR)
	{
		cout << "listen failed " << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	cout << "Server has started listening on " << port << endl;
	vector<SOCKET> clients;

	while (1) { // why this while loop and how does it work ?

		//accept connection from client
		SOCKET clientSocket = accept(listenSocket, nullptr, nullptr); // check what these nullptrs do 

		/*listen socket is used oto listen to other clients but this client socket is for this specific client only */
		if (clientSocket == INVALID_SOCKET)
		{
			cout << "Invalid CLient socket!" << endl;
		}

		clients.push_back(clientSocket);

		thread t1(InteractWithClient, clientSocket, std::ref(clients)); //why did we use std::ref here ?
		t1.detach();

	}
	
	closesocket(listenSocket);


	WSACleanup();
	return 0;
}