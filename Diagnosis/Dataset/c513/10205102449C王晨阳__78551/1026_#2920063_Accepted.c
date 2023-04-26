#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

int cmp(const void *a, const void *b){
    return *(long long *)a-*(long long *)b;
}

int main() {
    int n;
    long long sum=0;
    scanf("%d",&n);
    long long *p=(long long *) malloc(sizeof (long long )*n);
    for(int i=0;i<n;i++)
        scanf("%lld",&p[i]);
    qsort(p,n,sizeof (long long ),cmp);
    for(int i=0;i<n/2;i++){
        long long tmp=p[2*i]-p[2*i+1];
        tmp=tmp>0 ? tmp:-tmp;
        sum+=tmp;
    }
    printf("%lld\n",sum);
    return 0;
}
