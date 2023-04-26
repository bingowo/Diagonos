#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
int f(long long int x)
{
    if(x<0)x=-x;
    while((x/10)!=0)
    {
        x=x/10;
    }
    return (int)x;
}
int cmp(const void*a,const void*b)
{
    long long int p1=*((long long int*)a);
    long long int p2=*((long long int*)b);
    if(f(p1)!=f(p2))return f(p2)-f(p1);
    else {
        if(p1>p2)return 1;
        else return -1;
    }



}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        long long int *a=(long long int*)malloc(sizeof(long long int)*n);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&a[j]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
          for(int j=0;j<n;j++)
        {
            printf("%lld ",a[j]);
        }
        printf("\n");



    }

}
