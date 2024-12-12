#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int fd;
	char buf[1024] = "Hello World\n";

	//fd = open("/usr/include/stdio.h", O_RDONLY);
	//printf("%d\n", fd);
	//fd = open("/usr/include/stdio.h", O_RDONLY);
        //printf("%d\n", fd);
	//close(fd);
	
	if ((fd=open("a.txt", O_WRONLY)) == -1) {
		perror("Cannout open:");
		exit(1);
	}
	printf("fd = %d\n", fd);
	
	write(fd, buf, 12);

      	close(fd); 
	return 0;
}
