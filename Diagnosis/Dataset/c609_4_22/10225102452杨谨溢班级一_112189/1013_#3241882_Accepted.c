# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
int main()
{
	//(a+bi)*(i-1) = -(a+b) + (a-b)i    每四次形成一个循环 可用一个二维数组表示
	char numx[50] = { 0 };
	scanf("0x%s", numx);
	if (numx[0] == '0') {
		printf("0"); return 0;
	}
	int length = strlen(numx);
	long long int a, b;
	long long int qr = 0, qi = 0;
	for (int i = 0; i < length; ++i)
	{
		int n;
		if (isalpha(numx[i]))  n = numx[i] - 'A' + 10;
		else n = numx[i] - '0';
		int X[4] = {0};
		int x = 0;
		while (n>0)
		{
			X[x++] = n & 1;
			n = n >> 1;
		}
		for (x = 3; x >= 0; --x)
		{
			a = X[x] - qr - qi;
			b = qr - qi;
			qr = a;
			qi = b;
		}
	}
	if (qi == 0)  printf("%lld\n", qr);
	else
	{
		if (qr != 0)
		{
			printf("%lld", qr);
			if (qi > 0)  printf("+");
		}
		if (qi == 1) printf("i\n");
		else if (qi == -1 ) printf("-i\n");
		else
		{
			printf("%lldi\n", qi);
		}
	}
	return 0;
}