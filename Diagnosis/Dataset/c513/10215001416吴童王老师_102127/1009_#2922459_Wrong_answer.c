#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void solve(char *s) 
{
    int b1,c;
    for (int j = b1 = 0; j < 8; ++j) 
   (void)(b1 += c % 2), c >>= 1;
int s1 = 0, bytes = strlen(s), i, j;
for (int i = 0; i < bytes; i++)
{
    unsigned char c = s[i];
    for (j = 0; j < 8; j++)
        s1 += c % 2, c >>= 1;
}
int gcd(int a, int b)//如何定义求最大公因数的函数在这里
{return a ? gcd(b % a, a) : b;}
int g=gcd(s1,bytes*8); 
printf("%d/%d\n",s1/g, bytes*8/g);
}
int main()
{
	int T;
    scanf("%d",&T);
    while (T--)
    { 
        char s[121];
        
        gets(s);
        solve(s);
    } 
	return 0;
}


