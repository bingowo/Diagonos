#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 121
int max(int m,int n)
{
    if(m>n)m=m-n;
    else n=n-m;
    return max(m,n);
}

int main()
{
    int i,n,sum,d,x,y,b,j,m;
    char s[N];
    scanf("%d",&n);
    gets(s);
    for(i=0;i<n;i++)
    {
        gets(s);
        sum=0;
        for(x=0,b=1,d=0;s[x]!='\0';x++)
           {
               y=s[x]-'0';
               while(y)
               {if(y&b)d++;
                y>>=1;}
                sum=sum+d;
           }
           m=sum;
           sum=sum/max(m,x*8);
           x=x*8/max(m,x*8);
        printf("%d/%d\n",sum,x*8);
        for(j=0;j<x;j++)s[i]='\0';
    }
    return 0;}

