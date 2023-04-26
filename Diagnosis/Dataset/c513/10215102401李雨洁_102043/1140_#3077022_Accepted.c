#include <stdio.h>
#include <stdlib.h>
typedef struct SSS
{
    int sign;
    int cnt;
} sss;
int cmp(const void*_a,const void*_b)
{
    int *a=(int*)_a;
    int *b=(int*)_b;
    return*a-*b;
}
int main()
{
    int n,m,x; sss a[110];
    scanf("%d",&n); scanf("%d",&m);
    int temp=m;
    for(int j=0; j<m; j++)
    {
        scanf("%d",&a[j].cnt);
        a[j].sign=1;
    }
    for(int i=1; i<n; i++)
    {
        scanf("%d",&m);
        for(int j=0; j<m; j++)
        {
            scanf("%d",&x);
            for(int k=0; k<temp; k++)
            {
                if(x==a[k].cnt)
                { a[k].sign++; break; }
            }
        }
    }
    int c[110]; int k=0;
    for(int i=0; i<temp; i++)
    {
        if(a[i].sign==n) c[k++]=a[i].cnt;
    }
    qsort(c,k,sizeof(c[0]),cmp);
    for(int i=0; i<k; i++) printf("%d ",c[i]);
    return 0;
}
