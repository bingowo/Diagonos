#include<stdio.h>
#include<string.h>
#include<malloc.h>
char* htob(char s[20])
{
	int k; char t[80];
	for (int i = 0; i < strlen(s); i++)
	{
		int d; 
		if (s[i] >= 'A')d = s[i] - 'A' + 10;
		else d = s[i] - '0';
		unsigned int flag = 0x8;
		while (flag)
		{
			if (d&flag) t[k++] = '1';
			else t[k++] = '0';
			flag = flag >> 1;
		}
	}
	t[k] = 0;
	return &t;
}
int main()
{
	char hex[20];
	scanf("%s", hex);
	char* binary = (char*)malloc(sizeof(char)* 80);
	binary = htob(hex);
	long long int qr = 0, qi = 0;
	long long int a, b;
	for (int i = 0; binary[i]; i++)
	{
		int r = binary[i] - '0';
		a = -qr - qi + r;
		b = qr - qi;
		qr = a; qi = b;
	}
	free(binary);
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
