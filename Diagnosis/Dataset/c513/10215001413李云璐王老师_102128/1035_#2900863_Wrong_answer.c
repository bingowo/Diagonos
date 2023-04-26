#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{int r;int h;long long int mj;}yz;

void sort(yz*s,int n)
{
    int cmp(const void*a1,const void*a2)
    {
        yz a=*(yz*)a1;
        yz b=*(yz*)a2;
        if(a.mj>b.mj) return -1;
        else if(a.mj<b.mj) return 1;
        else return b.r-a.r;
    }
    qsort(s,n,sizeof(yz),cmp);
}


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
    sort(s,n);
    long long int maxr=s[0].r,di,ce=0,zong;
    for(int k=0;k<m;k++)
    {ce+=s[k].mj;
    if(s[k].r>maxr) maxr=s[k].r;}
    di=maxr*maxr;
    zong=di+ce;
    printf("%lld",zong);
    return 0;
    }