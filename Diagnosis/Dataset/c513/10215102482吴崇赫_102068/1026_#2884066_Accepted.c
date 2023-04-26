#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 100005

/*typedef struct
{
    long long x;
    long long y;
}point;*/

int cmp(const void* a,const void* b)
{
    if(*(long long*)a!=*(long long*)b)return *(long long*)a>*(long long*)b?1:-1;
    return 0;
}

int main(){
    long long a[N]={0};
    int n;scanf("%d\n",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long ans=0;
    for(int k=0;k<n-1;k+=2)ans=ans+a[k+1]-a[k];
    printf("%lld",ans);
    return 0;
}
