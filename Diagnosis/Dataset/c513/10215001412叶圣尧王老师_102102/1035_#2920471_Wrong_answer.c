#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
   else if(c->S>d->S)return 1;
        else return -1;
   
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
        s[t].sum=2*(pow(r,2)+r*h);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    long long sq=s[1].sum;
    for(int t=1;t<m;t++)sq=sq+s[t].sum-s[t].S;
    printf("%lld",sq);
    
}