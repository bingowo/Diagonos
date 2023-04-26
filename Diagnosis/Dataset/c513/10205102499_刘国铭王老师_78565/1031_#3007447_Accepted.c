#include <stdio.h>
#include <stdlib.h>

int a[1001]={0},b[1001]={0};
int cmp1(const void *a,const void *b)//0.1.2
{
    return (*(int*)a)>(*(int*)b);
}

int cmp2(const void *a,const void *b)//2.1.0
{
    return (*(int*)a)<(*(int*)b);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int res=0;
        for(int j=0;j<n;j++)
            scanf("%d",&a[j]);
        for(int j=0;j<n;j++)
            scanf("%d",&b[j]);
        qsort(a,n,sizeof(int),cmp1);
        qsort(b,n,sizeof(int),cmp2);
        for(int j=0;j<n;j++)
        {
            res+=a[j]*b[j];
        }
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}
