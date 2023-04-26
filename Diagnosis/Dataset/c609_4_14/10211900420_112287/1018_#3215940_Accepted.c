#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp1(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int sum,*a,i,n;
    sum=0;
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp1);
    for(i=0;i<n;i=i+2)
    {
        sum=sum+a[i+1]-a[i];
    }
    printf("%d",sum);
    free(a);
    return 0;
}
