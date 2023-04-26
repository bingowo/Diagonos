#include<stdio.h>
#include<stdlib.h>
struct circle
{ int r;
   int h;
    int sh,ce;
};
int cmp1(const void*a,const void*b)
{ struct circle x,y;
  x=*((struct circle*)a);
  y=*((struct circle*)b);
    return  2*x.r*x.h-2*y.r*y.h;
}
int main()
{int m,n,i,x,j,count;; struct circle a[1100]; long long int sum=0,ce=0,sh=0,ans=0;
sum=0;
scanf("%d %d\n",&n,&m);
for(i=0;i<n;i++)
{scanf("%d %d\n",&a[i].r,&a[i].h);
a[i].sh=a[i].r*a[i].r;
a[i].ce=2*a[i].r*a[i].h;
}
qsort(a,n,sizeof(a[0]),cmp1); 
count=1;
for(i=0;i<n;i++)
{
sum+=a[i].sh;
sum+=a[i].ce;
for(j=0;j<n&&count<m;j++)
{if(j==i||a[i].r<a[j].r) continue;
     sum+=a[j].ce;
    count++;
}
if(count==m)
{ if(ans<sum) ans=sum;}
}
printf("%lld",ans);
}