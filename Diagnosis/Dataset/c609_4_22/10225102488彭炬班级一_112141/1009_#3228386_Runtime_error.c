#include <stdio.h>
#include <string.h>

void solve(char *s)
{

}
int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char s[100];
        gets(s);
        solve(s);
        int s1 = 0, bytes = strlen(s), i, j;
        for (i = 0; i < bytes; i++)
        {
            unsigned char c = s[i];
            for (j = 0; j < 8; j++)
            {
                s1 += c % 2;
                c >>= 1;
            }
        }
        int g=gcd(s1,bytes*8);
        printf("%d/%d\n",s1/g, bytes*8/g);
    }
}
