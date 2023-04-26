#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

long long A[1000005];
int cmp(const void*a,const void*b)
{
    long long a1=*(long long*)a;
    long long b1=*(long long*)b;
    if(a1>b1) return 1;
    else return -1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
    qsort(A+1,n,sizeof(A[0]),cmp);
    long long ans,res=0;
    for(int i=1;i<=m;i++) res+=A[m]-A[i];
    ans=res;
    for(int i=m+1;i<=n;i++)
    {
        res+=(A[i]-A[i-1])*m;
        res-=(A[i]-A[i-m]);
        if(res<ans) ans=res;
    }
    printf("%lld\n",ans);
    return 0;
}
