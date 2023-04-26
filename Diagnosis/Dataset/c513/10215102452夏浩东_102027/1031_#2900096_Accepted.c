#include <stdio.h>
#include <stdlib.h>
int cmp1(const void *a,const void *b)
{
    int *A=(int*)a;
    int *B=(int*)b;
    return *A-*B;
}
int cmp2(const void *a,const void *b)
{
    int *A=(int*)a;
    int *B=(int*)b;
    return *B-*A;
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        long long int res=0;
        int num=0;
        scanf("%d",&num);
        int* L1=(int *)malloc(num*sizeof(int));
        int* L2=(int *)malloc(num*sizeof(int));
        for(int k=0;k<num;k++) scanf("%d",&L1[k]);
        for(int k=0;k<num;k++) scanf("%d",&L2[k]);
        qsort(L1,num,sizeof(int),cmp1);
        qsort(L2,num,sizeof(int),cmp2);
        for(int k=0;k<num;k++) res+=L1[k]*L2[k];
        free(L1);
        free(L2);
        printf("case #%d:\n",i);
        printf("%lld\n",res);
    }
    return 0;
}