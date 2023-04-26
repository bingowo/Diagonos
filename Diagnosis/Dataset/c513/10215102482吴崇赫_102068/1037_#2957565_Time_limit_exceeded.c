#include<stdio.h>
#include<stdlib.h>
#define N 1000005

int cmp(const void* a,const void* b)
{
    if(*(long long*)a!=*(long long*)b)return *(long long*)a>*(long long*)b?1:-1;
    else return 0;
}

int main()
{
    long long a[N],sum[N];
    int n,m;
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;++i)scanf("%lld",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    int l=0;
    for(int i=m-1,j=0;i<n;++i){
        sum[j]+=a[i]*(m-1);
        for(int k=i-1,cnt=0;cnt<m-1;--k,++cnt)sum[j]-=a[k];
        j++;l++;
    }
    qsort(sum,l,sizeof(sum[0]),cmp);
    printf("%lld\n",sum[0]);
    return 0;
}
