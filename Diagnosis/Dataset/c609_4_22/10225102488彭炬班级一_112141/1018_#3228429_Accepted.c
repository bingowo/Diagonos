#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    long long int a[100000];
    for(i = 0;i < n;i++)
        scanf("%lld",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    long long int sum = 0;
    for(int j = 0;j < n/2;j++)
    {
        long long int s = a[2*j+1] - a[2*j];
        sum += s;
    }
    printf("%lld",sum);
    return 0;
}
