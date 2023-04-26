#include<stdio.h>
#include<stdlib.h>
#define M 100000
int cmp(const void *a1,const void *b1)
{
    long* a=(long*)a1;
    long* b=(long*)b1;
    if(*a>=*b)
        return -1;
    else
        return 1;
}
int main()
{
    int n,i;
    long num[M]={0};
    long sum=0,temp=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&num[i]);
    }
    qsort(num,n,sizeof(long),cmp);
    for(i=0;i<n/2;i++)
    {
        temp=num[2*i+1]-num[2*i];
        if(temp<0)
            temp=-temp;
        sum=sum+temp;
    }
    printf("%ld",sum);
    return 0;
}