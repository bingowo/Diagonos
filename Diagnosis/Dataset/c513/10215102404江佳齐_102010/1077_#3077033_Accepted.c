#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int a[1005];
int cmp1(const void* p,const void* q)
{
    int* _a=(int*)p;
    int* _b=(int*)q;
    return(a[*_a]>a[*_b]?1:-1);
}
int cmp2(const void* p,const void* q)
{
    int* _a=(int*)p;
    int* _b=(int*)q;
    return(*_a>*_b?1:-1);
}
int main()
{
    int m,n;
    int b[510],c[510];
    memset(a,-1,sizeof(a));
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
    for(int s=0;s<k;s++)
    {
        printf("%d ",b[s]);
    }
    for(int s=0;s<j;s++)
    {
        printf("%d ",c[s]);
    }
    return 0;
}
