#include <stdio.h>
#include <stdlib.h>

int cmp(const void* e1, const void* e2);
int main()
{
    int T,N;
    long long *array=NULL;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        array = (long long*)malloc(N*sizeof(long long));
        for(int j=0;j<N;j++)
            scanf("%lld",array+j);
        qsort(array,N,sizeof(long long),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
            printf("%lld ",*(array+j));
        printf("\n");
        free(array);
    } 
    return 0;
}

int cmp(const void* e1, const void* e2)
{
    long long mask=1,n1 = *(long long*)e1, n2 = *(long long*)e2;
    long long m1=0,m2=0;
    for(int i=0;i<64;i++)
    {
        if(n1&mask)m1++;
        mask = mask << 1;
    }
    mask=1LL;
    for(int i=0;i<64;i++)
    {
        if(n2&mask)m2++;
        mask = mask << 1;
    }
    if(m1!=m2)
        return m2-m1;
    else return n1-n2; 
}