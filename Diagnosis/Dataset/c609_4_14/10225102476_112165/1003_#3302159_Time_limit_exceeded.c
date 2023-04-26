#include <stdio.h>
int main() {
	int a,i = 0;
	scanf("%d", &a);
	while(i<a)
	{
		int A[100];
		long long int x = 0;
		int b = 0;
		scanf("%lld", &x);
		do {
			A[b++] = x % 2333;
			x = x / 2333;
		} while (x != 0);

		for (int j = b - 1;j >= 0;j--) {
			printf("%d ", A[j]);
		}
		printf("\n");
	}
}

