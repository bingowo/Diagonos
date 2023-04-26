#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{long long int r;long long int h;long long int cmj;}yz;

void sort1(yz*s,long long int n)
{
    int cmp1(const void*a1,const void*a2)
    {
        yz a=*(yz*)a1;
        yz b=*(yz*)a2;
        if(a.cmj>b.cmj) return -1;
        else if(a.cmj<b.cmj) return 1;
       else return 0;
    }
    qsort(s,n,sizeof(yz),cmp1);
}//根据侧面积排

void sort2(yz*s,long long int n)
{
    int cmp2(const void*a1,const void*a2)
    {
        yz a=*(yz*)a1;
        yz b=*(yz*)a2;
        if(b.r>a.r) return 1;
        else if(b.r<a.r) return -1;
        else return 0;
    }
    qsort(s,n,sizeof(yz),cmp2);
}
//根据半径排

int main()
{
    long long int n,m;
    scanf("%lld%lld\n",&n,&m);
    yz*s=NULL;
    s=(yz*)malloc(n*sizeof(yz));
    for(long long int i=0;i<n;i++)
    {
        scanf("%lld%lld\n",&s[i].r,&s[i].h);
        s[i].cmj=2*s[i].r*s[i].h;
    }
    sort2(s,n);//先按半径排
    long long int zong[n-m+1];
    //轮流让半径大的做底,取比它半径小的侧面积前m大的圆柱，一共n-m+1种情况
    for(long long int l=0;l<n-m+1;l++)
    {
        long long int maxr=s[l].r,di,ce=0;
        di=maxr*maxr;
        sort1(s+l+1,n-l-1);//按侧面积排半径比它小的圆柱
        for(long long int k=l;k<l+m;k++)
         ce+=s[k].cmj;
         zong[l]=di+ce;
         sort2(s,n);//重新按半径排
    }
    long long int maxmj=zong[0];
    for(long long int g=0;g<n-m+1;g++)
    if(zong[g]>maxmj) maxmj=zong[g];
    printf("%lld",maxmj);//找出最大的面积
    
    
   
    return 0;
    }