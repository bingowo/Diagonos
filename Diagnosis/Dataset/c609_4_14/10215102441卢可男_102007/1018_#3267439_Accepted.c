#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{
    int*c=(int*)a;
    int*d=(int*)b;
    if(*c>*d)
        return 1;
    return -1;
}
int f(int n,int*a)
{   int sum=0,i;
    for(i=0;i<n/2;i++)
    {

        sum+=a[2*i+1]-a[2*i];
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    int*a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        //printf("%d ",a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    printf("%d\n",f(n,a));
    return 0;
}

