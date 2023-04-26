#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;

    return *x - *y;
}

int main()
{
    int n;
    scanf("%d",&n);
    long long int a[n];
    for( int i = 0 ; i < n ; i ++)
        scanf("%lld",&a[i]);

    qsort(a,n,sizeof(a[0]),cmp);

    long long int sum = 0;
    for ( int cnt = 0 ; cnt < n/2 ; cnt++)
        sum += abs( a[2*cnt] - a[2*cnt + 1]);
    printf("%lld\n",sum);
}
