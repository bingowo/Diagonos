#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a[121]={0};
    a[0]=0;
    a[1]=1;
    a[2]=1;
    for(int i=3;i<121;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        printf("case #%d:\n%lld\n",i,a[x]);
    }

    return 0;
}



