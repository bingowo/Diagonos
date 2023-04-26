#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int *a1=(int *)a,*b1=(int *)b;
    return *a1-*b1;
}
int main()
{
    int n,x[100001];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    qsort(x,n,sizeof(x[0]),cmp);
    int result=0;
    for (int i=0;i<n;i+=2)
    {
        result+=(x[i+1]-x[i]);
    }
    printf("%d",result);
    return 0;
}
