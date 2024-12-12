#include <stdio.h>
#include <signal.h>

void f(int signal) {
}

main() {
	signal(SIGALRM, f); //调用函数处理信号，如果不处理默认会杀死进程
	alarm(5); //定好闹钟,5秒后发出SIGALRM信号
	printf("About to sleep\n");
	pause();
	printf("Wake up\n");
}
