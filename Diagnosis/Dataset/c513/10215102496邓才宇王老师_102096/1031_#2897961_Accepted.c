#include <stdio.h>
#include <stdlib.h>
int cmp1(const void *p1,const void *p2)
{
    int* a=p1;
    int* b=p2;
    return *a-*b;
}
int cmp2(const void *p1,const void *p2)
{
    int* a=p1;
    int* b=p2;
    return *b-*a;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int num1[1000];
        int num2[1000];
        for(int j=0;j<n;j++)
            scanf("%d",&num1[j]);
        for(int k=0;k<n;k++)
            scanf("%d",&num2[k]);
        qsort(num1,n,4,cmp1);
        qsort(num2,n,4,cmp2);
        long long int ans=0;
        for(int l=0;l<n;l++)
        {
            ans=ans+num1[l]*num2[l];
        }
        printf("case #%d:\n%lld\n",i,ans);
    }
}
