#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <thread>

using namespace std;

#pragma comment(lib, "ws2_32.lib")

/*
	initialize socket

	create socket

	connecy to the server

	send/recv

	close the socket

*/

bool Initialize()
{
	WSADATA data;
	return WSAStartup(MAKEWORD(2, 2), &data) == 0;
}

void Send_Message(SOCKET s) {
	cout << "enter your your chat name :" << endl;
	string name;
	getline(cin, name);
	string message;

	while (1) {
		getline(cin, message);
		string msg = name + " : " + message;
		int bytessent = send(s, msg.c_str(), msg.length(), 0);
		if (bytessent == SOCKET_ERROR)
		{
			cout << "Error sending message!" << endl;
			break;
		}
		if (message == "quit")
		{
			cout << "stopping the application!" << endl;
			break;
		}

	}

	closesocket(s);
	WSACleanup();
}

void Receive_Message(SOCKET s) {
	char buff[4096];
	int recvlength;
	string msg = "";
	while (1) {
		recvlength = recv(s, buff, sizeof(buff), 0);
		if (recvlength <= 0)
		{
			cout << "Disconnected from the server !" << endl;
			break;
		}
		else {
			msg = string(buff, recvlength);
			cout << msg << endl;
		}
	}
	closesocket(s);
	WSACleanup();

}

int main() {
	if (!Initialize())
	{
		cout << "Initialize WinSock failed" << endl;
	}
	SOCKET s;
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET)
	{
		cout << "invalid socket created!" << endl;
		return 1;
	}

	int port = 12345;
	string serveraddress = "127.0.0.1";
	sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	inet_pton(AF_INET, serveraddress.c_str(), &serveraddr.sin_addr);

	if (connect(s, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr)) == SOCKET_ERROR)
	{
		cout << "not able to connect to server!" << endl;
		closesocket(s);
		WSACleanup();
		return 1;
	}

	cout << "client successfully connected to server" << endl;

	//send/recv

	thread sender_thread(Send_Message, s);
	thread receiver_thread(Receive_Message, s);

	sender_thread.join();
	receiver_thread.join();

	return 0;
}