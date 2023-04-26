#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 121



int main()
{
    int i,n,sum,d,x,y,b,k;
    char s[N];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        gets(s);
        for(k=0;s[k]!='\0';k++);
        sum=0;
        for(x=0,b=1,d=0;x<k;x++)
           {
               y=s[x]-'0';
               while(y)
               {if(y&b)d++;
                y>>=1;}
                sum=sum+d;
                printf("%d/%d\n",sum,k*8);
           }

        
        for(i=0;i<d;i++)s[i]='\0';
    }
    return 0;}

