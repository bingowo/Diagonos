#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}

int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    int *p=(int *) malloc(sizeof (int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    qsort(p,n,sizeof (int),cmp);
    long long sum=0;
    for(int i=0;i<m-1;i++)
        sum+=(p[m-1]-p[i]);
    printf("%lld\n",sum);
    return 0;
}
