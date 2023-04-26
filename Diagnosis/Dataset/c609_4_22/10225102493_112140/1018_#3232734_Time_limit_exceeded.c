#include <stdio.h>
#include <stdlib.h>


int cmp(void*a,void*b)
{
    return *(int*)a>*(int*)b?1:-1;
}



int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int sum=0;
    for(i=1;i<n;i+=2)
    {
        sum=sum+a[i];
    }
    for(i=0;i<n-1;i-=2)
    {
        sum=sum-a[i];
    }
    printf("%d",sum);
    return 0;
}