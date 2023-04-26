#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int k,n,i,j;scanf("%d %d",&k,&n);int a[n+1];
    a[1]=0;a[2]=1;
    for(i=3;i<=n;i++)
    {
        a[i]=0;
        if(i-k<1)j=1;
        else j=i-k;
        for(;j<i;j++)a[i]+=a[j];
    }
    printf("%d",a[n]);
}