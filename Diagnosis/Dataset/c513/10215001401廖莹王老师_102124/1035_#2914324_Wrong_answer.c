#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long long r;
    long long h;
    long long sd;
    long long sc;
    long long sh;
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
    if(r1->sh>r2->sh)return 1;
    else return -1;

}
int cmp2(const void*a,const void*b)
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
   long long sum1=0,sum2=0;
   scanf("%d %d",&n,&m);
   for(i=0;i<n;i++)
   {
       a[i].r=0;a[i].h=0;a[i].sd=0;a[i].sc=0;
       scanf("%lld",&a[i].r);
       scanf("%lld",&a[i].h);
       a[i].sd=a[i].r*a[i].r;
       a[i].sc=2*a[i].r*a[i].h;
       a[i].sh=a[i].sd+a[i].sc;
   }
   qsort(a,n,sizeof(a[0]),cmp1);
   sum2=a[n-1].sh;
   qsort(a,n-1,sizeof(a[0]),cmp);
       for(i=0;i<m-1;i++)
   {
       sum2=sum2+a[i].sc;
   }
   qsort(a,n,sizeof(a[0]),cmp);
   qsort(a,m,sizeof(a[0]),cmp2);
  sum1=a[0].sh;
   for(i=1;i<m;i++)
   {
       sum1=sum1+a[i].sc;
   }

   if(sum1>sum2)
   printf("%lld",sum1);
   else printf("%lld",sum2);
    return 0;
}
