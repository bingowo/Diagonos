#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct st
{
  long long sum;
  long long S;
};

int cmp(const void*a,const void*b)
{
   struct st*c=(struct st*)a;
   struct st*d=(struct st*)b;
   if(c->sum>d->sum)return -1;
   else if(c->sum<d->sum)return 1;
   else {if(c->S>d->S)return 1;
        else return -1;}

}

int main()
{
    int n,m;scanf("%d %d",&n,&m);struct st s[n];
    for(int t=0;t<n;t++)
    {
        int r,h;
        scanf("%d%d",&r,&h);
        s[t].sum=0;s[t].S=0;
        s[t].S=pow(r,2);
        s[t].sum=2*r*h;
    }
    qsort(s,n,sizeof(s[0]),cmp);
    long long sq=s[0]+s[0].S.sum;int e=1;
    for(int t=1;t<n&&e<m;t++)if(s[t].S<=s[t-1].S){sq=sq+s[t].sum+s[t].S;e++;}
    printf("%lld",sq);

}
