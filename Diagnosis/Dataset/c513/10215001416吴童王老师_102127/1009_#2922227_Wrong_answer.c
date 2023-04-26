#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void solve(char *s) 
{
    int b1,c,s01;
    s01=strlen(s)*8;
    for (int k=b1=0; k< 8; k++) 
    b1 += c % 2, c >>= 1;
int s1 = 0, bytes = strlen(s), i, j;
for (int i = 0; i < bytes; i++)
{
    unsigned char c = s[i];
    for (j = 1; j < 9; j++)
        s1 += c % 2, c >>= 1;
}
int gcd(int a, int b)//如何定义求最大公因数的函数在这里
{return a ? gcd(b % a, a) : b;}
int g=gcd(s1,bytes*8); 
printf("%d/%d\n",s1/g, bytes*8/g);
}
int main()
{
	int T,d[100];
	gets(d);
	solve(d);
    scanf("%d",&T);
    while (T--)
    { 
        char s[121];
        gets(s);
        solve(s);
    } 
	return 0;
}


