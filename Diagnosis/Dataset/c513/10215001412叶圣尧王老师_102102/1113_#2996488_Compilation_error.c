#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{
    int a[100];
}big;

void add(big *c,big *d)
{
    int i,carry=0;
    for(i=0;i<101;i++)
    {
        int t=c.a[i]+d.a[i]+carry;
        c.a[i]=t%10;
        carry=t/10;
    }
}

int main()
{
    int k,n,i,j;scanf("%d %d",&k,&n);big x[101]={{0}};
    x[1].a[0]=1;
    for(i=3;i<=n;i++)
    {
        if(i-k<1)j=1;
        else j=i-k;
        for(;j<i;j++) add(x[i],x[j]);
    }
    j=100;
    while(a[j]==0)j--;
    for(;j>=0;j++)
    printf("%d",a[j]);
}