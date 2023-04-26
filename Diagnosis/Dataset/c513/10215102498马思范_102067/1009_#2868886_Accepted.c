#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}
int main()
{
    int a;
    char s[150];
    int u;
    scanf("%d",&a);
    getchar();
    for(int j=0;j<a;j++)
    {
        gets(s);
        int len=strlen(s);
        int m=0;
        for(int i=0;i<strlen(s);i++)
        {   u=(unsigned char)s[i];
            while(u!=0)
        {
                m=m+u%2;
                u=u/2;
        }
        }
            int g = gcd(m, len*8);
            printf("%d/%d",m/g,len*8/g);
            printf("\n");
    }
    return 0;
}