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
    long long int min;
    int n,m;
    scanf("%d %d",&n,&m);
    long long int nums[10000];
    for(int i=0;i<n;i++) scanf("%lld",&nums[i]);
    qsort(nums,n,sizeof(nums[0]),cmp);
    long long int tmp=0;
    for(int j=0;j<m;j++) tmp+=nums[0]-nums[j];
    min=tmp;
    long long tmp1=tmp;
    for(int i=1;i<n-m+1;i++)
    {
        tmp=tmp1+nums[i]-nums[i+m-1]-(nums[i-1]-nums[i])*(m-1);
        tmp1=tmp;
        if(tmp<min) min=tmp;
    }
    printf("%lld",min);
}