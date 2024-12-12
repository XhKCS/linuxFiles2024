#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[]) {
	int fdin, fdout;
	char buf[1024];
	int n;	
	
	if (ac!=3) {
		printf("参数个数不匹配\n");
		exit(1);
	}

	if ((fdin=open(av[1], O_RDONLY)) == -1) {
		perror("Cannout open:");
		exit(1);
	}
	if ((fdout=open(av[2], O_WRONLY|O_CREAT, 0644)) == -1) {
		perror("Cannout open:");
		exit(1);
	}
	
	// 边读边写	
	while((n=read(fdin, buf, sizeof(buf)))>0){
		write(fdout, buf, n);
	}

	close(fdin);
	close(fdout);

	return 0;
}
