#include <stdio.h>

main() {
	int rv;
	if ((rv = fork()) == -1) {
		perror("fork fail\n");
	}
	else if (0 == rv) {
		printf("I am child, I am %d\n", getpid());
	}
	else {
		printf("I am parent, I am %d\n", getpid());
	}

}
