#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    long long int *p1=(long long int *)a;
    long long int *p2=(long long int *)b;
    return *p2-*p1;

}
int main()
{
    int n;unsigned long long int t=0;
    scanf("%d",&n);
    long long int a[10001];
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(long long int),cmp);
    for (int i=0;i<n;i=i+2)
        t=t+a[i]-a[i+1];
    printf("%lld",t);

}
