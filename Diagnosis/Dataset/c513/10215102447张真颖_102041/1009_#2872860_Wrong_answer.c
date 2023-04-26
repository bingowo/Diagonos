#include <stdio.h>
#include <stdlib.h>


int gcd(int m,int n)
{
    int a=m,b=n;
    if(a<b)
        m=b,n=a;
    return n==0?m:gcd(n,m%n);
}

int f(char ch)
{
    int num=0;
    while(ch)
    {
        if(ch%2) num++;
        ch/=2;
    }
    return num;
}

int main()
{
    int n,g,num=0,len=0;
    char ch;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        while((ch=getchar())!='\n')
        {
            num+=f(ch);
            len+=8;
        }
        g=gcd(num,len);
        num/=g,len/=g;
        printf("%d/%d\n",num,len);
    }
    return 0;
}