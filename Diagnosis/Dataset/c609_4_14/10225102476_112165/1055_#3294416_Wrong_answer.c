#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, c = 0;
	char x,y;
	scanf("%d%c%d%c %d", &a, &x, &b, &y, &c);
	int t = 0;
	int m = a;
	int n = b;
	while (t < c) {
		if (x == '-')
			a = a * m + b * n;
		else
			a = a * m - b * n;
		b = m * b + a * n;
		t++;
		
	}
	printf("%d%c%d%c",a,x,b,y);
	return 0;
}