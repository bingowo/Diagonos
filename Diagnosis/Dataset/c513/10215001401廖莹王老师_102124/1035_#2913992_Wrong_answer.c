#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long long r;
    long long h;
    long long sd;
    long long sc;
}yuanzhu;
int cmp(const void*a,const void*b)
{
    yuanzhu  *r1,*r2;
    r1=(yuanzhu*)a;
    r2=(yuanzhu*)b;
    if(r1->sc>r2->sc)return -1;
    else if(r1->sc<r2->sc)return 1;
    else
    {
        if(r1->r>r2->r)return -1;
        else return 1;
    }
}
int cmp1(const void*a,const void*b)
{
    yuanzhu  *r1,*r2;
    r1=(yuanzhu*)a;
    r2=(yuanzhu*)b;
    if(r1->r>r2->r)return -1;
    else return 1;

}
int main()
{
   int n,m,i;
   yuanzhu a[1010];
   long long sum=0;
   scanf("%d %d",&n,&m);
   for(i=0;i<n;i++)
   {
       a[i].r=0;a[i].h=0;a[i].sd=0;a[i].sc=0;
       scanf("%d",&a[i].r);
       scanf("%d",&a[i].h);
       a[i].sd=a[i].r*a[i].r;
       a[i].sc=2*a[i].r*a[i].h;
   }
   qsort(a,n,sizeof(a[0]),cmp);
   qsort(a,m,sizeof(a[0]),cmp1);
   sum=a[0].sc+a[0].sd;
   for(i=1;i<m;i++)
   {
       sum=sum+a[i].sc;
   }
   printf("%lld",sum);
    return 0;
}
