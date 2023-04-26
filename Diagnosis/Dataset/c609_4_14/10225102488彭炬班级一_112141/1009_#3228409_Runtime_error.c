#include <stdio.h>
#include <string.h>

int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        char s[100];
        gets(s);
        int s1 = 0, l = strlen(s), i, j;
        for (i = 0; i < l; i++)
        {
            unsigned char c = s[i];
            for (j = 0; j < 8; j++)
            {
                s1 += c % 2;
                c >>= 1;
            }
        }
        int g=gcd(s1,l*8);
        printf("%d/%d\n",s1/g, l*8/g);
    }
}
