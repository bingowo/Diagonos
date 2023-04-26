#include <stdio.h>
#include <stdlib.h>
int number(long long int a)
{
    int n=0,i;
    for(i = 0;i<64;i++)
    {
        long long int mask = 1LL<<i;
        if(a&mask) n++;
    }
    return n;
}
int cmp(const void *a,const void *b)
{
    int m,n;
    m = number(*(long long int *)a);n = number(*(long long int *)b);
    if(m<n) return 1;
    else if(m == n && *(long long int*)a>*(long long int *)b) return 1;
    else return -1;
}
void sort(long long int *p,int n)
{
    qsort(p,n,sizeof(long long int),cmp);
}
int main()
{
    int T,i,N[10],j;
    scanf("%d",&T);
    long long int a[T][10000];
    for(i = 0;i<T;i++)
    {
        scanf("%d",&N[i]);
        for(j = 0;j<N[i];j++)
            scanf("%lld",&a[i][j]);
    }
    for(i = 0;i<T;i++)
    {   printf("case #%d:\n",i);
        sort(a[i],N[i]);
        for(j = 0;j<N[i];j++)
        printf("%lld%c",a[i][j],j!=N[i]-1?' ':'\n');
    }
    return 0;

}