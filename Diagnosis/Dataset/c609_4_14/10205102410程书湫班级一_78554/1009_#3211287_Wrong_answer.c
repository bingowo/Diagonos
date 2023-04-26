#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b)
{
    int temp;
    while(b!=0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        char s[200];
        gets(s);
        int t=0,b=0;
        for(int j=0;j<strlen(s);j++)
        {
            unsigned char ch=s[i];
            while(ch!=0)
            {
                t+=(ch&1);
                ch=ch>>1;
            }
            b=b+8;
        }
        int g=gcd(t,b);
        printf("%d/%d\n",t/g,b/g);
    }
    return 0;
}
