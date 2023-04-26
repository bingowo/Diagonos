#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    int *p1=(int*)a;
    int *p2=(int*)b;
    if(*p1<*p2)
    {
        return 1;
    }
    else
        return -1;
}

int main()
{
    int A[100];
    long long int sum=0;
    int *p=A;
    int count,count1;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        scanf("%d",&A[count1-count-1]);
    }
    qsort(p,count1,sizeof(int),cmp);
    for(int i=0;i<count1;i=i+2)
    {
        sum=sum+A[i]-A[i+1];
    }
    printf("%lld",sum);

}
