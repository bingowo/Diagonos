#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b){
    if(*(int *)a<=*(int *)b)
        return 1;
    return -1;
}

int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    long long *p=(long long *) malloc(sizeof (long long )*n);
    for(int i=0;i<n;i++)
        scanf("%lld",&p[i]);
    qsort(p,n,sizeof (long long ),cmp);
    long long sum=0;
    long long *result=(long long *) malloc(sizeof (long long )*(n-m+1));
    for(int i=0;i<=n-m;i++){
        for(int j=i+1;j<i+m;j++)
            sum+=(p[i]-p[j]);
        result[i]=sum;
        sum=0;
    }
    qsort(result,n-m+1,sizeof (long long ),cmp);
    printf("%lld\n",result[n-m]);
    return 0;
}
