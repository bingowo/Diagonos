#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1005
int cmpa(const void* a,const void* b)
{
    int* num1=(int*)a;
    int* num2=(int*)b;
    if(*num1>*num2)
        return 1;
    else
        return -1;
}
int cmpb(const void* a,const void* b)
{
    int* num1=(int*)a;
    int* num2=(int*)b;
    if(*num1<*num2)
        return 1;
    else
        return -1;
}
int main()
{
    int i,j,k;
    int T,N;
    int a[M]={0};
    int b[M]={0};
    int res;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        res=0;
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            scanf("%d",&a[j]);
        }
        for(j=0;j<N;j++)
        {
            scanf("%d",&b[j]);
        }
        qsort(&a[0],N,sizeof(int),cmpa);
        qsort(&b[0],N,sizeof(int),cmpb);
        for(j=0;j<N;j++)
        {
            res=res+a[j]*b[j];
        }
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}