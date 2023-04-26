#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int *A=(int*)a;
    int *B=(int*)b;
    return *A-*B;
}
int main()
{
    int num=0,sum=0;
    scanf("%d",num);
    int *L=(int*)malloc(num*sizeof(int));
    for(int i=0;i<num;i++)
    {
        scanf("%d",L[i]);
    }
    qsort(L,num,sizeof(int),cmp);
    for(int i=0;i<num-1;i+=2)
    {
        sum+=(L[i+1]-L[i]);
    }
    printf("%d",sum);
    return 0;
}