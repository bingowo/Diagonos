#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b)
{
    long long i,j,i0,j0;
    i0=a;j0=b;
    i=a;j=b;
    if (i < 0) i = (-1)*i;
    if (j < 0) j = (-1)*j;
    int m1=0,m2=0;
    while (i) { m1 = i % 10 ;i /= 10;}
    while (j) { m2 = j % 10 ;j /= 10;}
    if (m1 == m2)
    {
        if(i0>j0) return -1;
        else return 1;
    }
    else if(m1>m2) return -1;
    else return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        long long int A[10001];
        int j=0;
        while(j<N)
        {
            scanf("%lld",&A[j]);
            j++;
        }
        qsort(A,N,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for(int a=0;a<N;a++) printf("%lld ",A[a]);
        printf("\n");
    }
    return 0;
}
