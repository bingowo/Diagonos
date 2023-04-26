#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{
    int a[100];
    int len;
}big;

int add(big *c,int k1,int k2)
{
    int i,carry=0;
    for(i=0;i<c[k1].len||i<c[k2].len;i++)
    {
        int t=c[k1].a[i]+c[k2].a[i]+carry;
        c[k1].a[i]=t%10;
        carry=t/10;
    }
    if(carry>0){c[k1].a[i]=1;i++;}
    return i;
}

int main()
{
    int k,n,i,j;scanf("%d %d",&k,&n);big x[101]={{0},0};
    x[1].len=1;x[2].a[0]=1;x[2].len=1;
    for(i=3;i<=n;i++)
    {
        if(i-k<1)j=1;
        else j=i-k;
        for(;j<i;j++) x[i].len=add(x,i,j);
    }

    for(j=x[n].len-1;j>=0;j--)
    printf("%d",x[n].a[j]);
}
