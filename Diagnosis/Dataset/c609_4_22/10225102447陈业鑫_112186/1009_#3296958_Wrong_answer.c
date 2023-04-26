#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
return a ? gcd(b % a, a) : b;
}

int main()
{
int t; scanf("%d", &t);
getchar();
for (int i = 0; i < t; i++)
{
char s[130];
fgets(s, 130, stdin);
// counts 1
int cnt = 0;
int len = strlen(s);
for (int j = 0; j < len; j++)
{
unsigned char c = (unsigned char) s[j];
for (int m = 0; m < 8; m++)
{
cnt += c % 2;
c >>= 1;
}
}
int g = gcd(cnt, len * 8);
printf("%d/%d\n", cnt / g, len * 8 / g);
}
return 0;
}