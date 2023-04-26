#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b)
{
    long long x=*(long long*)a;
    long long y=*(long long*)b;
    int f;
    if(x>y)f=1;
    else f=-1;
    return f;
}

int main()
{
    long long a=0;
    int n;
    long long num[100001]={};
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",&num[i]);
    qsort(num,n,sizeof(long long),cmp);
    for(int i=0;i<n;i+=2)
    {
        a+=(num[i+1]-num[i]);
    }
    printf("%lld",a);
    return 0;
}