#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{    return (*(int*)a>*(int*)b)?1:-1;}

int main()
{
    int n;scanf("%d",&n);
    int num[n],sum=0;
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    qsort(num,n,sizeof(int),cmp);
    for(int i=n-1;i>=0;i-=2) sum+=(num[i]-num[i-1]);
    printf("%d",sum);

    return 0; 
}