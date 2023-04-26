#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int cmp1(const void*_a,const void*_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return *a-*b;
}
int cmp2(const void*_a,const void*_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return *b-*a;
}
int main()
{
    int T;
    scanf("%d",&T);
    int n;
    int a[1100],b[1100];
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d",&b[j]);
        }
        qsort(a,n,sizeof(a[0]),cmp1);
        qsort(b,n,sizeof(b[0]),cmp2);
        int ans=0;
        for(int j=0;j<n;j++)
        {
            ans+=a[j]*b[j];
        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
    return 0;
}
