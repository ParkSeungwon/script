#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main() {
	struct sockaddr_in server_addr, client_addr;
	const int port = 2001, queue = 10, cl_size = sizeof(client_addr);
	char buffer[4096];
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)) == -1)
		cout << "bind() error" << endl;
	else cout << "binding" << endl;
	if(listen(server_fd, queue) == -1) cout << "listen() error" << endl;
	else cout << "listening port " << port << endl;
	int client_fd = accept(server_fd, (sockaddr*)&client_addr, (socklen_t*)&cl_size);
	if(client_fd == -1) cout << "accept error()" << endl;
	else {
		int n = read(client_fd, buffer, 4096);
		cout << buffer << endl;
		buffer[0] = 'h';
		write(client_fd, buffer, n);
	}
}

