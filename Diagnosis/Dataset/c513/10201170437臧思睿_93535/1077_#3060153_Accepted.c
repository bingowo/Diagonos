#include <stdio.h>
typedef struct{int x;int no;}P;

int cmp(const void*p,const void*q)
{
    int i;
    P *pp=(P *)p;
    P *pq=(P *)q;
    if((pp->no)!=(pq->no)){return (pp->no)-(pq->no);}
    else{return (pp->x)-(pq->x);}
}
int main()
{
    int i=0,j=0,m,n,flag;
    scanf("%d",&m);
    int a[m];
    while(i++<m)
    {
        scanf("%d",&a[i-1]);
    }
    scanf("%d",&n);
    P b[n];
    while(j++<n)
    {
        scanf("%d",&b[j-1].x);
        flag=0;
        for(i=0;i<m;i++)
        {
            if(b[j-1].x==a[i])
            {
                b[j-1].no=i;
                flag=1;
                break;
            }
        }
        if(flag==0){b[j-1].no=501;}
    }
    qsort(b,n,sizeof(P),cmp);
    for(i=0;i<n;i++)
    {
        printf("%d ",b[i].x);
    }
    return 0;
}
