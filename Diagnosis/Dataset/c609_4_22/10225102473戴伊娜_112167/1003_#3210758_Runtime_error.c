#include <stdio.h>
#include <stdlib.h>

int trans(long long int m,int t)
{
    m=m/2333;
    t++;
    if(m>2332)
    {
        return trans(m,t);
    }
    else
    printf("%d ",m);
    return t;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    long long int *p;
    p=a;;
    for(int i=0;i<n;i++)
        scanf("%lld",*p++);
    int i,j,t;
    for(i=0;i<n;i++)
    {
        t=0;j=0;
        for(j=0;a[i]>2332;j++)
        {
            t=0;
            t=trans(a[i],t);
            long long int b=pow(2333,t);
        a[i]=a[i]-a[i]/b*b;
        }
        if(a[i]==0)
        {
            for(;j<t;j++)
                printf("0 ");
        }
        printf("%lld\n",a[i]);
    }
    return 0;
}
