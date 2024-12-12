#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int fdin, fdout;
	char buf[1024];
	int n;	

	if ((fdin=open("hi.c", O_RDONLY)) == -1) {
		perror("Cannout open:");
		exit(1);
	}
	if ((fdout=open("hello.c", O_WRONLY)) == -1) {
		perror("Cannout open:");
		exit(1);
	}
	printf("fdin = %d, fdout = %d\n", fdin, fdout);
	
	// 边读边写	
	while((n=read(fdin, buf, sizeof(buf)))>0){
		write(fdout, buf, n);
	}

	close(fdin);
	close(fdout);

	return 0;
}
