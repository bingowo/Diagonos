#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Gcd(int m,int n)
{
    if(n==0)
       return m;
    return Gcd(n,m%n);
}
int main()
{
    int a;
    char s[120];
    scanf("%d",&a);
    for(int j=0;j<a;j++)
    {
        scanf("%s",s);
        int m=0;
        int h=0;
    for(int i=0;i<strlen(s);i++)
    {   unsigned char u=s[i];
        for(int c=0;c<8;c++)
        {
                m=m+u%2;
                u=u/2;
                h++;
        }
    }
        int g = Gcd(m, strlen(s) * 8);
        printf("%d/%d",m/g,strlen(s)*8/g);
        printf("\n");
    }
    return 0;
}
