#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{int r;int h;long long int mj;}yz;

void sort1(yz*s,int n)
{
    int cmp1(const void*a1,const void*a2)
    {
        yz a=*(yz*)a1;
        yz b=*(yz*)a2;
        if(a.mj>b.mj) return -1;
        else if(a.mj<b.mj) return 1;
        else return b.r-a.r;
    }
    qsort(s,n,sizeof(yz),cmp1);
}//根据侧面积排

void sort2(yz*s,int n)
{
    int cmp2(const void*a1,const void*a2)
    {
        yz a=*(yz*)a1;
        yz b=*(yz*)a2;
        return b.r-a.r;
    }
    qsort(s,n,sizeof(yz),cmp2);
}
//根据半径排

int main()
{
    int n,m;
    scanf("%d%d\n",&n,&m);
    yz*s=NULL;
    s=(yz*)malloc(n*sizeof(yz));
    for(int i=0;i<n;i++)
    {
        scanf("%d%d\n",&s[i].r,&s[i].h);
        s[i].mj=2*s[i].r*s[i].h;
    }
    sort2(s,n);
    long long int zong[n-m+1];
    for(int l=0;l<n-m+1;l++)
    {
        long long int maxr=s[l],di,ce=0;
        di=maxr*maxr;
        sort1(s+l+1,n-l-1);
        for(int k=l+1;k<l+m+1;k++)
         ce+=s[k].mj;
         zong[l]=di+ce;
    }
    long long int maxmj=zong[0];
    for(int g=0;g<n-m+1;g++)
    if(zong[g]>maxmj) maxmj=zong[g];
    printf("%lld",maxmj);
    
    
   
    return 0;
    }