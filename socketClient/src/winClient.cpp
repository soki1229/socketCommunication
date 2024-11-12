#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

int main(int argc, char* argv[])
{
	int ret = 0;
	string buffer = "Hello.";

	WSADATA wsa_data;
	SOCKADDR_IN addr;

	WSAStartup(MAKEWORD(2, 0), &wsa_data);

	const auto server = socket(AF_INET, SOCK_STREAM, 0);
	inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(5555);

	ret = connect(server, reinterpret_cast<SOCKADDR*>(&addr), sizeof(addr));
	cout << "Connected to server! (ret:" << ret << ")" << endl;

	ret = send(server, buffer.c_str(), buffer.size(), 0);
	cout << "Message sent... (ret:" << ret << ")" << endl;

	ret = closesocket(server);
	cout << "Socket closed. (ret:" << ret << ")" << endl << endl;

	WSACleanup();
}