/* ------------------------ Server impementation -----------------------*/
//Socket Programming Tutorial In C For Beginners | Part 1 | Eduonix
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h> //socket progs
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>

#define PORT 9001
int main(int argc, char** argv){

	int socket_fd, client_socket;
	struct sockaddr_in address;
	char buffer[1024] = {0};
	char hello[256] = "Hello from Mangal server";
	//1A. CREATE SOCKET
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	//1B. SET SOCKET PARAMS
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	//2.BIND SOCKET TO THE PORT
	bind(socket_fd, (struct sockaddr*)&address, sizeof(address));

	//3.LISTEN ON THE SOCKET/PORT
	listen(socket_fd, 5);

	//4.ACCEPT THE REQUEST FROM CLIENT
	client_socket = accept(socket_fd, NULL, NULL);

	//5.SEND/RECEIVE DATA BETWEEN CLIENT AND SERVER
	send (client_socket, hello, sizeof(hello), 0);
	printf("SERVER:message send to client\n");
	recv(client_socket, &buffer, sizeof(buffer),0);
	printf("%s\n", buffer);

	//6.CLOSE THE SOCKET
	close(socket_fd);

	return 0;	
}
