#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 121
int max(int m,int n)
{
    if(m>n)m=m-n;
    else if(n>m)n=n-m;
    else if(m==n)return m;
    else return max(m,n);
}

int main()
{
    int i,n,sum,d,x,y,b=1,j,m,h,g;
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
               y=s[x]-'0'+48;
               for(h=0;h<8;h++)
               {
                   if(y&b)d++,y>>=1;
                   else y>>=1;
               }
                sum=sum+d;
                d=0;
           }
           m=sum;
           g=x*8;
           sum=sum/max(m,g);
           x=g/max(m,g);
        printf("%d/%d\n",sum,x);
        for(j=0;j<g;j++)s[j]='\0';
    }
    return 0;}
