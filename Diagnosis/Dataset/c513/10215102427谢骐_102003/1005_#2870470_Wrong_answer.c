#include <stdio.h>

int main(void)
{
	int n, i = 0;
	scanf("%d", &n);
	while (n--) {
		printf("case #%d:\n", i++);
		double octnum;
		scanf("%lfo", &octnum);
		printf("%f\n", octnum);
	}
	return 0;
}