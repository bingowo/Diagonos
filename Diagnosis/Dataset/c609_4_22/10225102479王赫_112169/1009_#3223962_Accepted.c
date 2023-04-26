#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ZM(int a, int b)//a<b  辗转相除法
{
	int n = 0;
	while (a%b)
	{
		n = a % b;
		a = b;
		b = n;
	}
	return n > 0 ? n : 1;
}
int main()
{
	int t = 0;
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		int zi = 0;
		int mu = 0;
		char str[125]; char c;
		int e = 0;
		while ((c = getchar()) != '\n')
		{
			str[e++] = c;
		}
		str[e] = '\0';
		for (int i = 0; i < e; ++i)
		{
			/*if (isdigit(str[i]))
			{
				int m = str[i] - '0';
				while (isdigit(str[++i]))
				{
					m = m * 10 + str[i] - '0';
				}
				int n = 32;
				mu += 32;   // long long ???
				while (n--)
				{
					if ((m & 1) == 1)  zi++;
					m = m >> 1;
				}
			}
			else*/
			{
				int n = 8;
				char m = str[i];
				mu = mu + 8;
				while (n--)
				{
					if ((m & 1) == 1)  zi++;
					m = m >> 1;
				}
			}
		}
		int zm = ZM(zi, mu);
		zi = zi / zm;
		mu = mu / zm;
		printf("%d/%d\n", zi,mu);
	}
	return 0;
}