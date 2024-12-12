#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int fd;
	char buf[1024];

	//fd = open("/usr/include/stdio.h", O_RDONLY);
	//printf("%d\n", fd);
	//fd = open("/usr/include/stdio.h", O_RDONLY);
        //printf("%d\n", fd);
	//close(fd);
	
	if ((fd=open("/dev/input/mice", O_RDONLY)) == -1) {
		perror("Cannout open:");
		exit(1);
	}
	printf("fd = %d\n", fd);
	int n;
	while ((n=read(fd, buf, sizeof(buf))) > 0) {
		printf("%.*s\n", n, buf);
	}

      	close(fd); 
	return 0;
}
