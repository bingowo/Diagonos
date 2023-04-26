#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int a[1010];
int cmp1(const void* p,const void* q)
{
    int* a1=(int*)p;
    int* b1=(int*)q;
    return(a[*a1]>a[*b1]?1:-1);
}
int cmp2(const void* p,const void* q)
{
    int* a1=(int*)p;
    int* b1=(int*)q;
    return(*a1>*b1?1:-1);
}
int main()
{
    memset(a,-1,sizeof(a));
    int m,n;
    int b[510],c[510];
    scanf("%d",&m);
    int x=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        a[x]=i;
    }
    scanf("%d",&n);
    int i=0,k=0,j=0;
    for(i=0,k=0,j=0;i<n;i++)
    {
        scanf("%d",&x);
        if(a[x]!=-1)
        {
            b[k]=x;k++;
        }
        else
        {
            c[j]=x;j++;
        }
    }
    qsort(b,k,sizeof(b[0]),cmp1);
    qsort(c,j,sizeof(c[0]),cmp2);
    for(int m=0;m<k;m++)
    {
        printf("%d ",b[m]);
    }
    for(int m=0;m<j;m++)
    {
        printf("%d ",c[m]);
    }
    return 0;
}
