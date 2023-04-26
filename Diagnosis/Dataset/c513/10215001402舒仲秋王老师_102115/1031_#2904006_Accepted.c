#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void * b)
{
    long int d1,d2;
    d1=*((long int*)a),d2=*((long int*)b);
    return d1-d2;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        long int n,j,num1[2000],num2[2000];
        scanf("%ld",&n);
        for(j=0;j<n;j++) scanf("%ld",&num1[j]);
        for(j=0;j<n;j++) scanf("%ld",&num2[j]);
        qsort(num1,n,sizeof(num1[0]),cmp);
        qsort(num2,n,sizeof(num2[0]),cmp);
        long int sum=0;
        for(j=0;j<n;j++) sum+=num1[j]*num2[n-j-1];
        printf("case #%d:\n%ld\n",i,sum);
    }
    return 0;
}
