#include <stdio.h>
#include <stdlib.h>


int cmp1(const void* a,const void* b)
{
    int *pa=(int*)a;  int *pb=(int*)b;
    return (*pa>*pb)?-1:1;
}

int cmp2(const void* a,const void* b)
{
    int *pa=(int*)a;  int *pb=(int*)b;
    return (*pa>*pb)?1:-1;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&n);
        int* vec1=(int*)malloc(n*sizeof(int));
        int* vec2=(int*)malloc(n*sizeof(int));
        int j;
        for (j=0;j<n;j++)
            scanf("%d",&vec1[j]);
        for (j=0;j<n;j++)
            scanf("%d",&vec2[j]);
        qsort(vec1,n,sizeof(int),cmp1);
        qsort(vec2,n,sizeof(int),cmp2);
        long long result=0;
        for (j=0;j<n;j++)
            result+=vec1[j]*vec2[j];
        printf("%lld\n",result);
    }
    return 0;
}
