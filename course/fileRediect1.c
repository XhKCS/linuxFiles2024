#include <stdio.h>
#include <fcntl.h>

int main() {
	close(1); //关闭标准输出
	int fd;
	fd = open("temp.txt", O_WRONLY|O_CREAT, 0644);
	printf("Hello World, %d\n", fd);
	
	return 0;
}
