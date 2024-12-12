#include <stdio.h>
#include <unistd.h>
int main() {
	int rv;
	printf("About to execute ls\n");
	rv = fork();
	if (0 == rv) {
		execlp("ls", "ls", "/", "-l", NULL);
	}else {
		wait(NULL);
		printf("After execution\n");
	}
	return 0;
}
