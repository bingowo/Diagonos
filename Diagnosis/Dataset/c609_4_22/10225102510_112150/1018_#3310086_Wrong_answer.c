#include<stdlib.h>
#include<stdio.h>
#define N 10001
int cmp(const void* a,const void* b)
{
    return (*(int*)a)-(*(int*)b);
}
int main()
{
    int n,a,sum;
    scanf("%d",&n);
    int x[N];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        x[i]=a;
    }
    qsort(x,n,sizeof(int),cmp);
    for(int i=0;i<n-1;i=i+2)
        sum=sum+x[i+1]-x[i];
    printf("%d",sum);
    return 0;
}
