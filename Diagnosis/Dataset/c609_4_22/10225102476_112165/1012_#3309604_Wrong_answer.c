#include<stdio.h>
#include<math.h>
int main()
{
	int a = 0, i = 0;
	scanf("%d", &a);
	while (i < a) {
		char A[1000000] = { 0 };
		scanf("%s", A, 55);
		int n = 2, t = 2;
		while (A[n] >= '0' && A[n] <= '7')
			n++;
		double c = 0, d = 0;
		while (t < n) {
			c = (double)(A[t] - '0');
			d += c / (double)pow(8, t-1);
			t++;
		}
		int b = 3 * (n - 2);
		printf("case #%d:\n",i);
		printf("%.*lf\n",b, d);
		i++;
	}
}