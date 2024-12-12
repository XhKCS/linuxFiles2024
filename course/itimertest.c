#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void f() {
	printf("Hello\n");
}
main() {
	struct itimerval mytime;
	mytime.it_value.tv_sec = 3;
	mytime.it_value.tv_usec = 500000;
	mytime.it_interval.tv_sec = 0;
        mytime.it_interval.tv_usec = 500000;
	
	signal(SIGALRM, f);
	setitimer(ITIMER_REAL, &mytime, NULL);
	while(1) {
		pause();
	}
}
