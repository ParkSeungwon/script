#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main() {
	char buffer[4096];
	struct sockaddr_in server_addr;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_family = PF_INET;
	server_addr.sin_port = htons(2001);
	int client_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(-1 == connect(client_fd, (sockaddr*)&server_addr, sizeof(server_addr)))
		return -1;
	write(client_fd, "GET /", 5);
	read(client_fd, buffer, 4096);
	cout << buffer << endl;
	close(client_fd);
}
