#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,j,a[50];
    scanf("%d",&T);
    for(j=4;j<50;j++)
    {
        a[0]=1;
        a[1]=2;
        a[2]=4;
        a[3]=8;
        a[j]=a[j-1]+a[j-2]+a[j-3]+a[j-4];
    }
    for(i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%d\n",a[n-1]);
    }
    return 0;
}
