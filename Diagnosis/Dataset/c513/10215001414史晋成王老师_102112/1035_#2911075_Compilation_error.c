#include<stdio.h>
#include<stdlib.h>
struct circle
{ int r;
   int h;
    
};
int cmp1(const void*a,const void*b)
{ struct circle x,y;
  x=*((struct circle*)a);
  y=*((struct circle*)b);
    return y.r-x.r;
}
};
int cmp2(const void*a,const void*b)
{ struct circle x,y;
  x=*((struct circle*)a);
  y=*((struct circle*)b);
    return y.r*y.h-x.r*x.h;
}
int main()
{int m,n,i,x; struct circle a[1100]; long long int sum=0,ce=0,sh=0;
sum=0;
scanf("%d %d\n",&n,&m);
for(i=0;i<n;i++)
{scanf("%d %d\n",&a[i].r,&a[i].h);
    
}
qsort(a,n,sizeof(a[0]),cmp1); 
sh=a[0].r*a[0].r;
sum+=sh;
qsort(a,n,sizeof(a[0]),cmp2);
for(i=0;i<m;i++)
{ ce=2*a[i].r*a[i].h;
   sum+=ce;
    }
printf("%lld",sum);
}