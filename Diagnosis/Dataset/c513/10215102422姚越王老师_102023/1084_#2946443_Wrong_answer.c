#include<stdio.h>
typedef unsigned long long ull;
ull pow(int a,int b)
{
    ull ans=1;
    for(int i=0;i<b;i++)ans*=a;
    return ans;
}
int main()
{
    int T,cas,n;scanf("%d",&T);
    for(cas=0;cas<T;cas++)
    {
        scanf("%d",&n);
        printf("%llu\n",pow(2,n));
    }
    return 0;
}