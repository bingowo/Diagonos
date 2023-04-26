# include <stdio.h>
# include <stdlib.h>

char CC[] = "0123456789abcdefg";
int main()
{
	char c = getchar();
	do
	{
		char str[100] = {0};
		str[0] = c;
		int f = 0;
		int i = 1;
		long long int H = 15; // 00000000 00001111 可以通过位运算改变1111的位置
		while ((c = getchar()) != '\n')
		{
			str[i++] = c;
			if (c == '.')  f = 1;
		
		}
		if (f)
		{
			double n = atof(str);
			double* np = &n;
			long long nn = *(long long*)np;
			for (int j = 0; j < 8; ++j)
			{
				long long int m = H << (8 * j);
				for (int e = 1; e > -1; --e)
				{
					long long int m1 = m << (4 * e);
					printf("%c", CC[(m1 & nn) >> (4 * e + 8 * j)]);
				}
				printf(" ");
			}
		}
		else
		{
			int n = atoi(str);
			for (int j = 0; j < 4; ++j)
			{
				long long int m = H << (8 * j);
				for (int e = 1; e > -1; --e)
				{
					long long int m1 = m<< (4 * e);
					printf("%c", CC[(m1 & n)>>(4*e+8*j)]);
				}
				printf(" ");
			}
		}
		printf("\n");
	} while ((c = getchar()) != EOF);
	return 0;
}