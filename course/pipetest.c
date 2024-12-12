#include <stdio.h>
#include <unistd.h>

main() {
	int pipefd[2];
	char buf[1024];
	int n;
	
	pipe(pipefd);

	write(pipefd[1], "hello", 5); //pipefd[1]是写管道
	n = read(pipefd[0], buf, sizeof(buf)); //pipefd[0]是读管道
	
	printf("%.*s\n", n, buf);
}
