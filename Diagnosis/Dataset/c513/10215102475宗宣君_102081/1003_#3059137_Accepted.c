#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    long long A = *(long long *)a,B = *(long long*)b;
    int k,num1 = 0,num2 = 0;
    for(k = 0;k<64;k++)
    {
        if((A&(1LL<<k))) num1++;
        if((B&(1LL<<k))) num2++;
    }
    if(num1<num2) return 1;
    else if(num1==num2&&A>B) return 1;
    else return -1;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int N,j,num[10000]={0};
        long long A[10000];
        scanf("%d",&N);
        for(j = 0;j<N;j++)
        {
            scanf("%lld",&A[j]);
        }
        printf("case #%d:\n",i);
        if(N==1) printf("%lld",A[0]);
        else
        {qsort(A,N,sizeof(long long),cmp);
        for(j = 0;j<N;j++)
            printf("%lld ",A[j]);
        }
        printf("\n");
    }
    return 0;
}

