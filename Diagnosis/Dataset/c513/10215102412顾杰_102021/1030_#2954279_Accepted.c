#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void*a,const void*b)
{
    long long x=*(long long*)a,y=*(long long*)b,x0,y0,fx,fy;
    if(x<0)x0=-1*x;else x0=x;if(y<0)y0=-1*y;else y0=y;
    do
    {
        fx=x0;
        x0/=10;
    }while(x0);
    do
    {
        fy=y0;
        y0/=10;
    }while(y0);
    if(fx!=fy)return fx>fy?-1:1;
    else return x<y?-1:1;
}
int main()
{
    int n,k,i,j;
    long long a[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        for(j=0;j<k;j++)scanf("%lld",&a[j]);
        qsort(a,k,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<k-1;j++)printf("%lld ",a[j]);
        printf("%lld\n",a[j]);
    }
}
