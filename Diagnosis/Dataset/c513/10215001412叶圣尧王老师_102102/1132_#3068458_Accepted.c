#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void output(int d,int t)
{
    int a[100]={0},i,j;
    for(i=0;d>0;i++)
    {
        a[i]=d%t;
        d=d/t;
    }
    while(a[i]==0)i--;
    while(i>=0)
    {
       if(a[i]>=10)printf("%c",'A'+a[i]-10);
       else printf("%d",a[i]);
       i--;
    }
    printf("\n");
}

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int n,d=0,digit;scanf("%d %d",&n,&digit);
        while(n>0)
        {
            d+=n%digit;
            n/=digit;
        }
        output(d,digit);
    }
}