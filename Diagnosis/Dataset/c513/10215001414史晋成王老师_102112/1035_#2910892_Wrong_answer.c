#include<stdio.h>
#include<stdlib.h>
struct circle
{ int r;
   int h;
    
};
int cmp(const void*a,const void*b)
{ struct circle x,y;
  x=*((struct circle*)a);
  y=*((struct circle*)b);
    return y.r-x.r;
}
int main()
{int m,n,i,x,sum,ce,sh; struct circle a[1100];
sum=0;
scanf("%d %d",&n,&m);
for(i=0;i<n;i++)
{scanf("%d %d",&a[i].r,&a[i].h);
    
}
qsort(a,n,sizeof(a[0]),cmp);    
for(i=0;i<m;i++)
{ ce=2*a[i].r*a[i].h;
   sh=a[i].r*a[i].r;
   sum+=ce;
   sum+=sh;
    
}
printf("%d",sum);
}