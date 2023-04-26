#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void*p1,const void*p2)
{
    int *a=(int*)p1;
    int *b=(int*)p2;
    return (*a-*b);
}
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;i=i+2)
    {
        sum=sum+abs(a[i+1]-a[i]);
    }
    printf("%d",sum);
    return 0;
}