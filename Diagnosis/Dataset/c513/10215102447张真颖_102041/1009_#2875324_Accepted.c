#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int m,int n)
{
    int a=m,b=n;
    if(a<b)
        m=b,n=a;
    return n==0?m:gcd(n,m%n);
}

int count(char value)
{
    int n=0;
    for(int i=0;i<8;i++)
    {
        if((value>>i)&1) n++;

    }
    return n;
}

int main()
{
    int n,g,num=0,len=0;
    char ch;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        num=0,len=0;
        while((ch=getchar())!='\n')
        {
            num+=count(ch);
            len+=8;
        }
        g=gcd(num,len);
        num/=g,len/=g;
        printf("%d/%d\n",num,len);
    }
    return 0;
}