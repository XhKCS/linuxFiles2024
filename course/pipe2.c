#include <stdio.h>
#include <unistd.h>

main() {
	int fd[2];
	int rv;

	pipe(fd);
	rv = fork();
	if (0 == rv) { //child
		close(fd[1]);
		close(0);
		dup(fd[0]);
		close(fd[0]);
		execlp("sort", "sort", NULL);
	}
	else { //parent
		close(fd[0]);
                close(1);
                dup(fd[1]);
                close(fd[1]);
                execlp("cat", "cat", "/usr/include/stdio.h", NULL);
	}

}
