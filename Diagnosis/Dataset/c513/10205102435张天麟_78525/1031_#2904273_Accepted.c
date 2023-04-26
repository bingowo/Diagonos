#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    int *aa=(int*)a,*bb=(int*)b;
    return *aa-*bb;
}
int main()
{
    int T,N;
    scanf("%d",&T);
    for(N=0;N<T;N++)
    {
        int n,i,a[1000],b[1000];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        qsort(a,n,sizeof(int),cmp);
        qsort(b,n,sizeof(int),cmp);
        int ans=0;
        for(i=0;i<n;i++)
        {
            ans+=a[i]*b[n-1-i];
        }
        printf("case #%d:\n%d\n",N,ans);
    }
    return 0;
}
