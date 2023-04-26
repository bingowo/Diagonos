#include<stdio.h>
#include<malloc.h>
int main()
{
	int a, i = 0;
	scanf("%d", &a);
	while (i < a) {
		long long int t, m = 0, r = 0;
		scanf("%ld", &t);
		if (t == 0)
			printf("0");
		else
		{
			m = t;
			while (m) {
				m = m / 2333;
				r++;
			}
			long long int* A = (long int*)malloc(r * sizeof(long int));
			int y = 0;
			while (y < r) {
				A[y] = t % 2333;
				t = (t-A[y]) / 2333;
				y++;
			}
			int n = 0;
			while (n < r) {
				printf("%lld ", A[r - n - 1]);
				n++;
			}
			printf("\n");
			i++;
		}
	}
}
