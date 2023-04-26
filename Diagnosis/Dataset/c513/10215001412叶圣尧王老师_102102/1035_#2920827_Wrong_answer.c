#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct st
{
  long long sr;
  long long sc;
  long long sh;
};
int cmp1(const void*a,const void*b)
{
   struct st*c=(struct st*)a;
   struct st*d=(struct st*)b;
   if(c->sc>d->sc)return -1;
   else if(c->sc<d->sc)return 1;
   else {if(c->sr>d->sr)return 1;
        else return -1;}
}
int cmp2(const void*a,const void*b)
{
   struct st*c=(struct st*)a;
   struct st*d=(struct st*)b;
   if(c->sh>d->sh)return -1;
   else if(c->sh<d->sh)return 1;
   else {if(c->sr>d->sr)return 1;
        else return -1;}
}

int main()
{
    int n,m;scanf("%d %d",&n,&m);struct st s[n];
    for(int t=0;t<n;t++)
    {
        int r,h;
        scanf("%d%d",&r,&h);
        s[t].sr=0;s[t].sh=0;s[t].sc=0;
        s[t].sr=pow(r,2);
        s[t].sh=2*r*h;
        s[t].sc=2*r*h+pow(r,2);
    }
    qsort(s,n,sizeof(s[0]),cmp1);
    long long sq=s[0].sc;
    qsort(s+1,n-1,sizeof(s[1]),cmp2);
    int e=1;
    for(int t=1;t<n&&e<m;t++)if(s[t].sr<s[t-1].sr){sq=sq+s[t].sh;e++;}
    printf("%lld",sq);

}
