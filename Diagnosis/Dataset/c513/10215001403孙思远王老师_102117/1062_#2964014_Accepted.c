#include <stdio.h>
#include <stdlib.h>
void zou(long long int a[50],int n)
{
    if(n<=50)
    {
        a[n]=a[n-1]+a[n-2]+a[n-3]+a[n-4];
        zou(a,n+1);
    }
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    int n=4;
    long long int a[50]={1,2,4,8};
    zou(a,n);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int m;
        scanf("%d",&m);
        printf("%lld\n",a[m-1]);
    }
    return 0;
}
