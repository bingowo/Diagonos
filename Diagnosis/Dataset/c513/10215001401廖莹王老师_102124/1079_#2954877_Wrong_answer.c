#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int l;
    int u;
}lu;
int cmp(const void*a,const void*b)
{
    int k1,k2;
    k1=*((int*)a);
    k2=*((int*)b);
    if(k2>=k1)return -1;
    else return 1;
}
int re[500500]={0};
int sum(int l,int u)
{
    int i=0;int k=0;
    l=l-1;u=u-1;
    for(i=l;i<=u;i++)k=k+re[i];
    return k;
}
void jisuan(int h)
{
    int n,m,i=0,j=0,k=0,d=0;
    int result=0;
    int p[1100];lu q[30];
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&p[i]);
    for(i=0;i<m;i++)scanf("%d %d",&q[i].l,&q[i].u);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n-i+1;j++)
        {re[d]=0;
         for(k=0;k<i;k++){re[d]=re[d]+p[k+j];}
         d++;
        }
    }
    qsort(re,d,sizeof(re[0]),cmp);
    printf("case #%d:\n",h);
    for(i=0;i<m;i++){result=sum(q[i].l,q[i].u);printf("%d\n",result);}
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
