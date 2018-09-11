/* ------------------------ Client implementation -----------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>

#define PORT 9001

int main (int argc, char** argv){
	
	//struct sockaddr_in address;
	struct sockaddr_in serv_addr;
	int socket_fd, connect_rslt;
	char buffer[1024] = {0};
	char hello[256] = "Hello from Mangal client";

	//1. CREATE SOCKET FD
	// here 3rd argument 0 = TCP
        socket_fd=socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family= AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	connect_rslt = connect(socket_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	
	if (connect_rslt < 0)
	{
		perror("connection failed Mangal\n");
		close(socket_fd);
	}

	recv(socket_fd, &buffer, sizeof(buffer), 0);
	printf("%s\n", buffer);
	send(socket_fd, hello, sizeof(hello),0);
	printf("CLIENT:message send to server\n");

	return 0;

}

