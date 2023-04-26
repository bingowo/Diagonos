#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}

int main()
{
    int p=0,n;
    char s[100];
    scanf("%d",&n);
    while(gets(zs)!=EOF)
    {
        int cnt=0;
        for(int i=0;i<strlen(s);i++)
        {
            int d=1;
            p=p+sizeof(char);
            for(int j=0;j<8;j++)
            {
                if(d&s[i]==1)cnt++;
                d=d<<1;
            }
        }
        int g=gcd(cnt,p);
        printf("%d/%d",cnt/g,p/g);
    }
    return 0;
}