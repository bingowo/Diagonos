#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void* a,const void* b)
{
    long long x=*(long long*) a;
    long long y=*(long long*) b;
    return x-y;
}

int main()
{
    int n;
    scanf("%d\n",&n);
    long long ans[100001];
    long long res=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&ans[i]);
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            res=res-ans[i];
        }
        if(i%2==1)
        {
            res=res+ans[i];
        }
    }
    printf("%lld",res);
}
