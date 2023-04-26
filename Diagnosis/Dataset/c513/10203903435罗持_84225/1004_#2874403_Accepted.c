#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void calint(int x)
{
	int ll = sizeof(x);
	unsigned char *pos = (unsigned char*) &x;
	for(int i=0;i<ll;i++)
	{
		printf("%02x",*(pos++));
		putchar(' ');
	}
	putchar('\n');
}
void caldouble(double x)
{
	int ll = sizeof(x);
	unsigned char *pos = (unsigned char*) &x;
	for(int i=0;i<ll;i++)
	{
		printf("%02x",*(pos++));
		putchar(' ');
	}
	putchar('\n');
}
int main(void)
{
	char s[50] = {0};
	while(scanf("%s",s)!=EOF)
	{
		int len = strlen(s);
		int flag = 1;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='.')
			{
				flag = 0;
				break;
			}
		}
		if(flag) calint(atoi(s));
		else caldouble(atof(s));
	}
	return 0;
}