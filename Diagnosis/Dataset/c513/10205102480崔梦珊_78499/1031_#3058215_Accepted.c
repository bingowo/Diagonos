#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int a[1000];
        int b[1000];
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d",&b[j]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp);
        long long ans=0;
        for(int k=0;k<n;k++)
        {
            ans=ans+a[k]*b[n-1-k];
        }
        printf("case #%d:\n%lld\n",i,ans);
    }
    return 0;
}
