#include <stdio.h>
#include<string.h>
int gcd(int a, int b)
    {return a ? gcd(b % a, a) : b;}

void solve(char *s)
{
    int s1 = 0;//1的位数
    int  bytes = strlen(s), i, j;
    for (i = 0; i < bytes; i++)
    {
        unsigned char c = s[i];
        for (j = 0; j < 8; j++)
          
            {s1 = s1+ c % 2;
            c =c>> 1;
            }

    }
    int g=gcd(s1,bytes*8);
    printf("%d/%d\n",s1/g, (bytes*8)/g);
}

int main()
{
	int T;
    scanf("%d\n",&T);
    while (T--)
    {
        char s[121];
        gets(s);
        solve(s);
    }
	return 0;
}