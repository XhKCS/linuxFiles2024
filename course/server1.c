#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>


int main(int ac, char *av[]) {
	int tcp_socket; //文件描述符
	tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	int fd; //server
	char buf[1024];	
	int n;
	
	if (ac < 2) {
		printf("USE: CMD PORT_NUM\n");
		exit(1);
	}
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(av[1]));	
	addr.sin_addr.s_addr = INADDR_ANY;

	if (-1 == bind(tcp_socket, (const struct sockaddr *) &addr, sizeof(addr))) {
		perror("Cannot bind\n");
		exit(1);
	}
	
	listen(tcp_socket, 1);
	while (1) {
		fd = accept(tcp_socket, NULL, NULL);

		//write(fd, "Hello from server", 17);

		n = read(fd, buf, sizeof(buf));	
		printf("Client: %.*s\n", n, buf);
		write(1, buf, n);
		close(fd);
	}

	return 0;
}
