#include<stdio.h>
#include<math.h>
int main()
{
	int a = 0;
	scanf("%d\n", &a);
	int i = 0;
	while (i < a) {
		char M[100];
		int y = 0;
		M[y] = getchar();
		while (M[y] == '1' || M[y] == '0' || M[y] == '-') {
			y++;
			M[y] = getchar();
		}
		int t = 0;
		while (M[t] == '1' || M[t] == '-' || M[t] == '0')
			t++;
		int d = 0, m = 0;
		int t1 = t;
		while (d <= t1) {
			if (M[d] == '1')
				m = m + pow(3, t - 1);
			else if (M[d] == '-')
				m = m - pow(3, t - 1);
			else
				m = m + 0;
			d++;
			t--;
		}
		printf("case #%d:\n", i);
		printf("%d\n", m);
		i++;
	}
}