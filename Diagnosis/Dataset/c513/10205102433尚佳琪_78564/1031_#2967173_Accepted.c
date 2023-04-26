#include <stdio.h>
#include <stdlib.h>
int cmp1(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int cmp2(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
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
        qsort(a,n,sizeof(a[0]),cmp1);
        qsort(b,n,sizeof(b[0]),cmp2);
        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp=temp+a[i]*b[i];
        }
        printf("case #%d:\n%d\n",i,temp);
    }
    return 0;
}
