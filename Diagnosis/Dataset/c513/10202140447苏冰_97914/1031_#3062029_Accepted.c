#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int cmp(const void*_a,const void*_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return *a-*b;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        int b[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp);
        int ans=0;
        for(int i=0,j=n-1;i<n;i++,j--)
        {
            ans=ans+a[i]*b[j];
        }
        printf("case #%d:\n",cas);
        printf("%d\n",ans);
    }
    return 0;
}
