#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000005

int cmp(const void* a,const void* b)
{
    if(*(long long*)a!=*(long long*)b)return *(long long*)a>*(long long*)b?1:-1;
    else return 0;
}

int main()
{
    int n,m;
    //printf("hello");
    scanf("%d%d\n",&n,&m);  // all->n  choose->m
    long long a[N]={0};long long b[N]={0};
    for(int i=0;i<n;++i){
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int pm=0;
    for(int i=1;i<n;++i){
        b[pm++]=a[i]-a[i-1];
    }
    qsort(b,pm,sizeof(b[0]),cmp);
    long long ans=0;
    for(int k=0;k<m-1;++k){
        int temp=k;
        while(temp>-1){
            ans+=b[temp];
            temp--;
        }
    }
    printf("%lld\n",ans);
    //printf("hello");
    return 0;
}
