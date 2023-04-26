#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000
int cmp(void* a,void* b)
{
    long long* num1=(long long*)a;
    long long* num2=(long long*)b;
    if(*num1>*num2)
        return -1;
    else
        return 1;
}
int main()
{
    int n,m;
    int i,j,k;
    long long num[N]={0};
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&num[i]);
    }
    qsort(&num[0],n,sizeof(long long),cmp);
    printf("%d",num[0]);
    return 0;
}