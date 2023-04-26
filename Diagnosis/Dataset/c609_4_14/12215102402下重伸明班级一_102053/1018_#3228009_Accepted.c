#include<stdio.h>
#include<stdlib.h>
int comp(const void*p1,const void*p2)
{
    int x;
    int n1,n2;
    n1=*(int*)p1;
    n2=*(int*)p2;
    x=n1-n2;
    if(x!=0)
    return -x;
}
int main()
{
    int x,y=0,a[100001];
    scanf("%d",&x);
    for(int i=0;i<x;i++)
        scanf("%d",&a[i]);
    qsort(a,x,sizeof(a[0]),comp);
    for(int k=0;k<x;k++)
        y=y+abs(a[k]-a[++k]);
    printf("%d",y);
}