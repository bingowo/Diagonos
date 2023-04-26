#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int m,int n)
/* 找最大公约数*/
{
    if(n>m)
    {
        int temp=m;
        m=n;
        n=temp;
    }
    if(m%n==0) return n;
    else return GCD(n,m%n);
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char s[120];
        gets(s);
        int len=strlen(s);
        int num=0,size=len*8;
        for(int j=0;j<len;j++)
        {
            int k=0;
            while((s[j]>>k))
            {
                if((s[j]>>k)&1) num++;
                k++;
            }
        }
        int x=GCD(num,size);
        printf("%d/%d\n",num/x,size/x);
    }
    return 0;
}
