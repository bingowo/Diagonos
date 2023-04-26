#include<stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    if(*(int *)a>*(int *)b) return 1 ;
    else return -1;
}
int main()
{
    int n,res = 0,i;
    scanf("%d",&n);
    int a[n];
    for(i = 0;i<n;i++)
    scanf("%d",&a[i]);
    qsort(a,n,4,cmp);
    for(i = n-1;i>0;i-=2)
    {
       res = res + abs(a[i]-a[i-1]);
    }
    printf("%d",res);
    return 0;
}
