#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int cmp(const void*_a,const void*_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return *a-*b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long sum=0;
    for(int i=0;i<n-1;i+=2)
    {
        sum=sum+a[i+1]-a[i];
    }
    printf("%lld\n",sum);
    return 0;
}
