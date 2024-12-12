#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	close(1); //关闭标准输出
	int fd;
	fd = open("lslist", O_WRONLY|O_CREAT, 0644);
	printf("Hello World, %d\n", fd);
	execlp("ls", "ls", NULL, "-l");
	return 0;
}
