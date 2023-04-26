#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}
// #define N 111111
// int a[N];
int main()
{
    int n; scanf("%d",&n);
    int a[n];
    for(int i = 0; i<n; i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    long long sum = 0;
    for(int i = 0; i<n; i+=2)
    {
        sum+=a[i+1]-a[i];
    }
    printf("%lld",sum);
    return 0;
}