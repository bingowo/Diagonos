#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 121
int max(int m,int n)
{
    if(m%n==0)return n;
    else if(n%m==0)return m;
    else if(m>n)m=m-n;
    else if(n>m)n=n-m;
    return max(m,n);
}

int main()
{
    int i=0,n=0,sum=0,d=0,x=0,y=0,b=1,j=0,m=0,h=0,g=0;
    char s[N];
    scanf("%d",&n);
    gets(s);
    for(i=0;i<n;i++)
    {
        gets(s);
        sum=0;
        y=0;
        for(x=0;s[x]!='\0';x++)
           {
               y=(int)s[x];
               for(h=0;h<8;h++)
               {
                   if(y&b)d++,y>>=1;
                   else y>>=1;
               }
                sum=sum+d;
                d=0;
           }
           g=x*8;
           m=max(sum,x*8);
           sum=sum/m;
           x=x*8/m;
        printf("%d/%d\n",sum,x);
        for(j=0;j<g;j++)s[j]='\0';
    }
    return 0;}