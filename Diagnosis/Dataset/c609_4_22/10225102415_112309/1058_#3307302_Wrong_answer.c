#include <stdio.h>

typedef long long int ll;

int main() {
	int a;
	scanf("%d", &a);
	int b;
	int cnt = 0;
	int ans[10000] = {0};
	if (a == 0) cnt = 1;
	while (a) {
		b = a % -2;
		a /= -2;
		if (b < 0) {
			a += 1;
			b += 2;
		}
//		if (a < 0) {
//			b = a % -2;
//			b += 2;
//			a /= -2;
//			a++; 
//		} else {
//			b = a % -2;
//			a /= -2;
//		}
		ans[cnt] = b;
		cnt++;
		//printf("*b:%d a:%d\n", b, a);
	}
	for (int i = cnt-1; i > -1; i--)
		printf("%d", ans[i]);
	return 0;
}