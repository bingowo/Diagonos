#include<stdio.h>
#include<math.h>
int main()
{
	char s[100] = { 0 };
	scanf("%s", s, 100);
	if (s[0] == '0' && s[1] != '.')
		printf("0");
	else
	{
		int i = 0;
		while (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '.')
			i++;
		int t = 0;
		while (t < i) {
			if (s[t] == '.')
				break;
			t++;
		}
		if (s[0] != '0')
		{
			int m = 0, n = 0;
			long long a = 0;
			while (m < t) {
				if (s[m] == '1')
					a += (long long int)pow(3, t - m - 1);
				else if (s[m] == '2')
					a -= (long long int)pow(3, t - m - 1);
				else
					a += 0;
				m++;
			}
			if (a >= 0 && s[t + 1] == '2')
				a--;
			else if (a < 0 && s[t + 1] == '1')
				a++;
			printf("%lld ", a);
			if (a < 0) {
				int v = t + 1;
				while (v <= i) {
					if (s[v] == '1')
						s[v] = '2';
					else if (s[v] == '2')
						s[v] = '1';
					v++;
				}
			}
		}
		if (s[t + 1] >= '1' && s[t + 1] <= '9')
		{
			int m = i - t - 1, n = 1;
			long long int c = 0;
			int m1 = m;
			while (t + n <= i) {
				if (s[t + n] == '1')
					c += (long long int)pow(3, m1 - 1);
				else if (s[t + n] == '2')
					c -= (long long int)pow(3, m1 - 1);
				n++;
				m1--;
			}
			if (c < 0 && s[0] != '0')
				c = c + (long long int)pow(3,m);
			printf("%lld %lld", c, (long long int)pow(3, m));
		}
	}


}