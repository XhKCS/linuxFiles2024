#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <utmp.h>
#include <time.h>

int main() {
	int fd;
	struct utmp buf;
	int n;
	time_t timeval;

	if ((fd = open("/var/run/utmp", O_RDONLY)) == -1) {
		perror("");
		exit(1);
	}
	
	while (read(fd, &buf, sizeof(struct utmp)) > 0) {
		if (USER_PROCESS == buf.ut_type) {
			timeval = buf.ut_time;
			printf("%s\t%s\t%.12s (%s)\n", buf.ut_user, buf.ut_line, 4+ctime(&timeval), buf.ut_host);
		}
	}
	
	close(fd);
	
	return 0;
}
