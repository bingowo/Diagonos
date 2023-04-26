#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct st
{
  long long sr;
  long long sh;
};
int cmp1(const void*a,const void*b)
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
        scanf("%lld %lld",&r,&h);
        s[t].sr=pow(r,2);
        s[t].sh=2*r*h;
        
    }
    qsort(s,n,sizeof(s[0]),cmp1);
    int i,j,count;long long maxn,max=0;
    for(i=0;i<n;i++)
    {
       maxn=s[i].sr+s[i].sh;count=1;
       for(j=0;j<n&&count<m;j++)
       {
           if(i==j||s[j].sr>s[i].sr)continue;
           maxn+=s[j].sh;count++;
       }
       if(m==count)max=max>maxn? max:maxn;
    }
    printf("%lld",max);
}
