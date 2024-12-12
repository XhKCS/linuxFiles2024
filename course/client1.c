#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>


int main(int ac, char *av[]) {
        //int tcp_socket; //文件描述符
        //tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;
        int fd; 
        char buf[1024];
        int n;

        if (ac < 3) {
                printf("USE: CMD IP_ADDR PORT_NUM\n");
                exit(1);
        }

        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(av[1]);
	addr.sin_port = htons(atoi(av[2]));


        if (-1 == connect(fd, (const struct sockaddr *) &addr,  sizeof(struct sockaddr_in))) {
                perror("Cannot bind\n");
                exit(1);
        }

        n = read(fd, buf, sizeof(buf));
	printf("Server: %.*s\n", n, buf);

	return 0;
}
