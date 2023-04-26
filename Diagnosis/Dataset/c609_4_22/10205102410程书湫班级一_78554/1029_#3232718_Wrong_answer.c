#include <stdio.h>
#include <stdlib.h>
int order[513];
int cmp(const void *a,const void *b)
{
    int aa=*((int *)a);
    int bb=*((int *)b);
    if(order[aa]!=-1&&order[bb]==-1) return -1;
    else if(order[aa]==-1&&order[bb]!=-1) return 1;
    else if(order[aa]==-1&&order[bb]==-1) return aa-bb;
    else return order[aa]-order[bb];
}
int main()
{
    int m;
    scanf("%d",&m);
    int a[501];
    for(int i=0;i<513;i++)
    {
        order[i]=-1;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
        order[a[i]]=i;
    }
    int n;
    scanf("%d",&n);
    int b[501];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    qsort(b,n,sizeof(b[0]),cmp);
    for(int i=0;i<n-1;i++) printf("%d ",b[i]);
    printf("%d",b[n-1]);
    return 0;
}
