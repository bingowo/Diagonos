#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main()
{
	char hex[20];
	scanf("%s", hex);
	char* t = (char*)malloc(sizeof(char)* 80);
	int k;
	for (int i = 0; i < strlen(hex); i++)
	{
		int d; 
		if (hex[i] >= 'A')d = hex[i] - 'A' + 10;
		else d = hex[i] - '0';
		unsigned int flag = 0x8;
		while (flag)
		{
			if (d&flag) t[k++] = '1';
			else t[k++] = '0';
			flag = flag >> 1;
		}
	}
	long long int qr = 0, qi = 0;
	long long int a, b;
	for (int i = 0;i<k; i++)
	{
		int r = t[i] - '0';
		a = -qr - qi + r;
		b = qr - qi;
		qr = a; qi = b;
	}
	if (qi == 0)
		printf("%lld\n", qr);
	else
	{
		if (qr != 0)
		{
			printf("%lld", qr);
			if (qi > 0)printf("+");
		}
		if (qi == 1)printf("i\n");
		else if (qi == -1)printf("-i\n");
		else
		{
			printf("%lld", qi); printf("i\n");
		}
	}
}
