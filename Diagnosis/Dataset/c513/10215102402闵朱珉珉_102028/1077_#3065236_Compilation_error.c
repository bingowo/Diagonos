#include <stdio.h>
#include <stdlib.h>
int q[11]={0},t=11;

int cmp(const void *a1,const void *b1)
{
    int *aa=(int *)a1,*bb=(int *)b1;
    if (q[*aa]!=q[*bb]) 
        return q[*bb]-q[*aa];
    else 
        return *aa-*bb;
}
int main()
{
    int m,n,a[501],b[501],len=0;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
        {
            scanf("%d",%a[m]);
            q[a[m]]=t;
            t--;
        }
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        {
            scanf("%d",%b[n]);
            len++;
        }
    qsort(b,n,sizeof(b[0]),cmp);
    for (int i=0;i<len;i++)
        printf("%d ",b[i]);
    return 0;
}