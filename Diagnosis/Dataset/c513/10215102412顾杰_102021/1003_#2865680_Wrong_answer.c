#include <stdio.h>
#include<string.h>
#include<math.h>
int cmp(const void*a,const void *b)
{
    int a0=*(int*)a,b0=*(int*)b,na=0,nb=0,n=1;
    while(n)
    {
        if(a0&n)na++;
        n<<=1;
    }
    n=1;
    while(n)
    {
        if(b0&n)nb++;
        n<<=1;
    }
    if(na==nb)return a0>b0?1:-1;
    return na>nb?-1:1;
}
int main() {
    int x,y,i,n,j,a[10000];
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&y);
        for(j=0;j<y;j++)
        {
            scanf("%d",&a[j]);
        }
        qsort(a,y,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<y-1;j++)printf("%d ",a[j]);
        printf("%d\n",a[j]);
    }
    return 0;
}
