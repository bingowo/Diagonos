#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(void *a,void *b)
{
    long long int *a1,*b1;
    a1=(long long int *)a;
    b1=(long long int *)b;
    if(*a1>*b1) return -1;
    if(*a1==*b1) return 0;
    return 1;
}
int cmp1(void *a,void *b)
{
    long long int *a1,*b1;
    a1=(long long int *)a;
    b1=(long long int *)b;
    if(*a1>*b1) return 1;
    if(*a1==*b1) return 0;
    return -1;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long int nums[1000000];
    for(int i=0;i<n;i++) scanf("%lld",&nums[i]);
    qsort(nums,n,sizeof(nums[0]),cmp);
    long long int res[1000000];
    memset(res,0,1000000);
    for(int i=0;i<n-m+1;i++)
    {
        for(int j=0;j<m;j++)
        {
            res[i]+=nums[i]-nums[i+j];
        }
    }
    qsort(res,n-m+1,sizeof(res[0]),cmp1);
    printf("%lld",res[0]);
}