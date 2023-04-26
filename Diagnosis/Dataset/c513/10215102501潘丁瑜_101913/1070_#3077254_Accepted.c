#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    int a[21]={0,2,4,7};
    for(i=4;i<21;i++)
    {
        a[i] = 2*a[i-1] - a[i-2] + a[i-3];
    }
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        printf("%d\n",a[n]);
    }
    return 0;
}
