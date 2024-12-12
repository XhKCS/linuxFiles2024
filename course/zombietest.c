#include <stdio.h>

main() {
	int rv;
	if ((rv = fork()) == -1) {
		perror("fork fail\n");
		exit(1);
	}
	else if (0 == rv) {
		printf("I am child, I am %d\n", getpid());
		sleep(5);
		exit(10);
	}
	else {
		printf("I am parent, I am %d\n", getpid());
		sleep(20);
		exit(100);
	}

}
