#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        long long int a[74]={0};
        int m;
        long long int k;
        a[0]=0;
        a[1]=1;
        a[2]=1;
        for(m=3;m<=n;m++)
        {
            a[m]=a[m-1]+a[m-2]+a[m-3];
        }
        if(n==0)
            k=0;
        if(n==1||n==2)
            k=1;
        printf("case #%d:\n",i);
        printf("%lld\n",a[n]);
    }
}