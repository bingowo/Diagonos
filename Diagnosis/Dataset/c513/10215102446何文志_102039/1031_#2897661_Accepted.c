#include <stdio.h>
#include <stdlib.h>

typedef struct Vector
{
    int r[1000];
}vector;

int cmp1(const void *a,const void *b)
{
    int A = *(int *)a,B = *(int *)b;
    return A-B;
}

int cmp2(const void *a,const void *b)
{
    int A = *(int *)a,B = *(int *)b;
    return B-A;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        int n = 0;
        scanf("%d",&n);
        vector v[2];memset(v,0,2*sizeof(vector));
        {
            for(int j = 0;j<n;j++)
            {
                scanf("%d",&v[0].r[j]);
            }
            for(int j = 0;j<n;j++)
            {
                scanf("%d",&v[1].r[j]);
            }
        }
        qsort(v[0].r,n,sizeof(v[0].r[0]),cmp1);
        qsort(v[1].r,n,sizeof(v[1].r[0]),cmp2);
        long long  res = 0;
        for(int k = 0;k<n;k++)
        {
            res+=v[0].r[k]*v[1].r[k];
        }

        printf("case #%d:\n%lld\n",i,res);

        //for(int j = 0;j<n;j++)
        //{
        //    printf("%d ",v[0].r[j]);
        //}
        //printf("\n");
        //for(int j = 0;j<n;j++)
        //{
        //    printf("%d ",v[1].r[j]);
        //}
        //printf("\n");
    }
    return 0;
}
