#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void *b)
{
    long long s1=*(long long *)a;
    long long s2=*(long long *)b;
    if(s1>s2)
        return -1;
    else
        return 1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long L[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&L[i]);
    }
    qsort(L,n,sizeof(L[0]),cmp);
    long long ans=0,temp=0;
    if (n == m){
        long long res = 0;
        for (int i=1;i<n;i++) res+=L[0]-L[i];
        ans=res;
    }
    else{
        long long res = 0;
        for (int i=1;i<m;i++) res+=L[0]-L[i];
        long long MIN = res;		//res无需重置，每一次计算都依赖上一次的值
        for (int i=1;i<=n-m;i++){
            res = res - (L[i-1]-L[i])*(m-1)+(L[i]-L[i+m-1]); /*第一个数后移一位，所以减去第一个与第二个间的差，
            计算数值时总共要发生m-1次相减，所以乘上m-1.再加上新的第一位与最后一位的差*/
            //MIN = min(MIN,res);
            MIN=MIN<res?MIN:res;
        }
        ans=MIN;
    }
    printf("%lld",ans);
    return 0;
}
