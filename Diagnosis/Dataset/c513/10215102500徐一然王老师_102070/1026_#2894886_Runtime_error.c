#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    long long int *p1=(long long int*)a;
    long long int *p2=(long long int*)b;
    if(*p1<*p2)
    {
        return 1;
    }
    else
        return -1;
}

int main()
{
    long long int A[10000];
    long long int sum=0;
    long long int *p=A;
    int count,count1;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        scanf("%lld",&A[count1-count-1]);
    }
    qsort(p,count1,sizeof(A[0]),cmp);
    for(int i=0;i<count1;i=i+2)
    {
        sum=sum+A[i]-A[i+1];
    }
    printf("%lld",sum);

}
