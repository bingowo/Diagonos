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
    long long sum=LLONG_MAX;
    int tag=0;
    for(int i=0;i<=n-m;i++){
        if(sum>(p[i]-p[i+m-1])){
            sum=p[i]-p[i+m-1];
            tag=i;
        }
    }
    sum=0;
    for(int i=tag+m-1;i>tag;i--)
        sum+=(p[tag]-p[i]);
    printf("%lld\n",sum);
    return 0;
}
