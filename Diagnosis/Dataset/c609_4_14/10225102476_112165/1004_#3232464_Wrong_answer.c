#include<stdio.h>
#include<math.h>
int main()
{
	int a, b;
	char M[100];
	scanf("%d %s %d", &a, &M, &b);
	int c = 0;
	while ((M[c] >= 'a' && M[c] <= 'z') || (M[c] >= 'A' && M[c] <= 'Z') || (M[c] >= '1' && M[c] <= '9'))
		c++;
	int q = 0;
	int t = 0;
	while (q<=c) {
		char d = M[q];
		int m = 0;
		if (d >= 'A' && d <= 'Z')
			m = d - 'A' + 10;
		else if (d >= 'a' && d <= 'z')
			m = d - 'a' + 10;
		else
			m = d;
		t = t + m * pow(a, c);
		c--;
	}
	int w = 0;
	while (t >= pow(b, w))
		w++;
	char S[100];
	int r = 0;
	while (r <= w) {
		S[r] = t / pow(b, w);
		r++;
	}
	printf("%s", S);
	return 0;
}