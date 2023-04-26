#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int l;
    int u;
}qujian;

int cmp(const void*a,const void*b)
{
    int aa=*((int*)a);
    int bb=*((int*)b);
    return aa-bb;

}

void makenew(int yuan[],int n,int *xin)
{
    int len,j=0,st,k,i;
    for(st=0;st<n;st++)
    {
        len=n-st;
        xin[j++]=yuan[st];
        for(i=1;i<len;i++,j++)
        {
            xin[j]=xin[j-1]+yuan[st+i];
        }
    }
    qsort(xin,j,sizeof(int),cmp);
    for(k=0;k<j;k++)
    //printf("test: xin[%d]=%d\n",k,xin[k]);

}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int j,m,n,k;
        int yuan[1010];
        long long ans[25];
        memset(ans,0,sizeof(long long)*25);
        int *xin=(int*)malloc(sizeof(int)*500510);
        qujian a[25];
        scanf("%d%d",&n,&m);
        for(j=0;j<n;j++)
        {
            scanf("%d",&yuan[j]);
        }
        for(j=0;j<m;j++)
        {
            scanf("%d%d",&a[j].l,&a[j].u);
        }
        makenew(yuan,n,xin);
        printf("case #%d:\n",i);
        for(j=0;j<m;j++)
        {
            for(k=a[j].l;k<=a[j].u;k++)
            {
                ans[j]+=xin[k-1];
            }
            printf("%lld\n",ans[j]);
        }

    }
    return 0;
}
