#include <stdio.h>

typedef long long int ll;

int main() {
	int a;
	scanf("%d", &a);
	int b, bio = 1, ans;
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
		ans += b * bio;
		bio *= 10;
		//printf("*b:%d a:%d\n", b, a);
	}
	printf("%d", ans);
	return 0;
}