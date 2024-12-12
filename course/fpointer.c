#include <stdio.h>
int sum(int x, int y) {
	return x+y;
}
int mul(int x, int y) {
	return x*y;
}

int f(int x, int y, int (*calc)(int, int)) {
	return calc(x, y);
}

main() {
	int ans = f(3, 5, sum);
	printf("ans = %d\n", ans);
}
