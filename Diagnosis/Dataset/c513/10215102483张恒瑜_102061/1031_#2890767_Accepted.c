#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        int n,i;
        scanf("%d",&n);
        int a[1010]={0},b[1010]={0};
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n;i++) scanf("%d",&b[i]);
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp);

        long long sum=0;
        for(i=0;i<n;i++) sum+=a[i]*b[n-1-i];
        printf("case #%d:\n%lld\n",t,sum);
        t++;
    }
    return 0;
}