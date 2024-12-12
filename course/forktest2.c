#include <stdio.h>

main() {
	fork();
	fork();
	fork();
	printf("I am %d\n", getpid());
	sleep(20);
}
