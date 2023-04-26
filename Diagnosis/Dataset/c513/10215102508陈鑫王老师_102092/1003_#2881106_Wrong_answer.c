#include<stdio.h>
#include<stdlib.h>
unsigned int num(long long int n)
{
    unsigned int a=0;
    while(n!=0)
    {
        if(n&1==1)a=a+1;
        n=(unsigned)n>>1;

    }
    return a;
}
int cmp(const void *a,const void* b)
{
    unsigned int m,n;
    m=num(*(long long int*)a);
    n=num(*(long long int*)b);
    if(m==n)return *(long long int*)a>*(long long int *)b?1:-1;
    else return m>n?-1:1;
}
void Sort(long long int *p,long long int n)
{
    qsort(p,n,sizeof(long long int),cmp);
}
int main()
{
    long long int T,i=0;
    scanf("ll%d",&T);
    getchar();
    long long int a[100000];
    while(i<T)
    {
        int N;
        scanf("%lld",&N);
        int j=0;
        getchar();
        while(j<N)
            {
                scanf("%lld",&a[j]);
                j=j+1;
            }
        Sort(a,N);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
        printf("%lld%c",a[k],k!=N-1?' ':'\n');
        i=i+1;
    }
}
