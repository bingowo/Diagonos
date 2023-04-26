#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(const void *q1,const void *q2)
{
    int *p1 = (int *)q1;
    int *p2 = (int *)q2;

    if(*p1 > *p2) return 1;
    if(*p1 < *p2) return -1;

}

int cmp2(const void *q1,const void *q2)
{
    int *p1 = (int *)q1;
    int *p2 = (int *)q2;

    if(*p1 > *p2) return -1;
    if(*p1 <= *p2) return 1;

}

int main()
{
    char method; scanf("%c",&method);
    int a[106],i=0;
    while(scanf("%d",&a[i])!=EOF) i++;
    if(method=='A')
        qsort(a,i+1,sizeof(int),cmp1);
    else if(method=='C')
        qsort(a,i,sizeof(int),cmp2);

    for(int j=0;j<i;j++)
    {
        if(a[j]!=a[j+1]) printf("%d ",a[j]);
        else continue;
    }

    return 0;
}