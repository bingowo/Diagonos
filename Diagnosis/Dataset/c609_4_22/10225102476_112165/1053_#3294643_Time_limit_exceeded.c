#include<stdio.h>
#include<math.h>
int main()
{
	int x = 0;
	int i = 0;
	scanf("%d", &x);
	while (i < x) {
		int a;
		scanf("%d", &a);
		a++;
		int t = 0;
		int m = 0;
		while(t!=m-1)
		{
			while (a > pow(10, m))
				m++;
			while (a / pow(10, t) * pow(10, t) - a / pow(10, t + 1) * pow(10, t + 1) != a / pow(10, t + 1) * pow(10, t + 1) - a / pow(10, t + 2) * pow(10, t + 2))
				t++;
			if (t != m - 1)
				a++;
		}
		printf("case #%d\n", i);
		printf("%d\n", a);
	}
}