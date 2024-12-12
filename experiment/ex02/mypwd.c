#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main() {
	char cwd[PATH_MAX]; //存储当前工作目录的绝对路径
	if (getcwd(cwd, sizeof(cwd)) == NULL) {
		perror("getcwd error\n");
		exit(1);
	}
	printf("%s\n", cwd);
	
	return 0;
}
