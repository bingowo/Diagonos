#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int x=*((int*)a),y=*((int*)b),cnt1,cnt2,m=x,n=y;
    if (x==0) cnt1=1;
    if (y==0) cnt2=1;
    while (x!=0)
    {
        x/=10;cnt1++;
    }
    while (y!=0)
    {
        y/=10;cnt2++;
    }
    if (cnt1<cnt2) return 1;
    else if (cnt1==cnt2)
    {
        if (m<n) return -1;
        else return 1;
    }
    else return -1;
}

int main()
{
    int a[100000],i=0;
    while ((scanf("%d",a+i))!=-1) i++;
    qsort(a,i,sizeof(int),cmp);
    for (int j=0;j<i;j++)
        printf("%d ",a[j]);
    return 0;
}
