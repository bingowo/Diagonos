#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int a[1000];
int cmp1(const void*a1,const void*b)
{
    return a[*(int*)a1]-a[*(int*)b];
}
int cmp2(const void*a1,const void*b)
{
    return *(int*)a1-*(int*)b;
}
int main()
{
    int b1[1000],b2[1000],na,nb,nb1=0,nb2=0,i,x;
    memset(a,0,1000);
    scanf("%d",&na);
    for(i=1;i<=na;i++)
    {
        scanf("%d",&x);
        a[x]=i;
    }
    scanf("%d",&nb);
    for(i=0;i<nb;i++)
    {
        scanf("%d",&x);
        if(a[x])b1[nb1++]=x;
        else b2[nb2++]=x;
    }
    qsort(b1,nb1,sizeof(b1[0]),cmp1);
    qsort(b2,nb2,sizeof(b2[0]),cmp2);
    for(i=0;i<nb1;i++)printf("%d ",b1[i]);
    for(i=0;i<nb2;i++)printf("%d ",b2[i]);
}
