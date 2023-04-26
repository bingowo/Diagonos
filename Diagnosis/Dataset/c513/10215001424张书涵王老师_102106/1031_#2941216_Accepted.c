#include <stdio.h>
#include <stdlib.h>

struct zuobiao
{
    int a[100000];
};

int cmp1(const void*a,const void*b)
{
    int *ap=(int *)a;
    int *bp=(int *)b;
    return (*bp-*ap);
}

int cmp2(const void*a,const void*b)
{
    int *ap=(int *)a;
    int *bp=(int *)b;
    return (*ap-*bp);
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        struct zuobiao b[2];
        int j,p;
        for(j=0;j<2;j++)
        {
            for(p=0;p<n;p++)
                scanf("%d",&b[j].a[p]);
        }
        qsort(b[0].a,n,sizeof(int),cmp1);
        qsort(b[1].a,n,sizeof(int),cmp2);
        int N=0;
        for(j=0;j<n;j++)
            N=N+b[0].a[j]*b[1].a[j];
        printf("case #%d:\n",i);
        printf("%d\n",N);
    }
}
