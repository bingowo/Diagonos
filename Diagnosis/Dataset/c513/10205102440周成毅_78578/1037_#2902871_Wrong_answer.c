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
    long long sum=0,res=0;
    for(int i=1;i<m;i++)
        sum+=(p[0]-p[i]);
    res=sum;
    for(int i=1;i<=n-m;i++){
        res=res-(m-1)*p[i-1]+m*p[i]-p[i+m-1];
        sum=sum>res ? res:sum;
    }
    printf("%lld\n",sum);
    return 0;
}
