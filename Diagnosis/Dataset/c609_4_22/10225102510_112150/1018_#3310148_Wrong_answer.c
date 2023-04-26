#include<stdlib.h>
#include<stdio.h>
int cmp(const void* a,const void* b)
{
    return (*(int*)a)-(*(int*)b);
}
int main()
{
    int n,a,sum;
    scanf("%d",&n);
    int x[n-1];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        x[i]=a;
    }
    qsort(x,n,sizeof(int),cmp);
    for(int i=0;i+1<n;i+=2)
            sum=sum+x[i+1]-x[i];
    printf("%d",sum);
    return 0;
}
