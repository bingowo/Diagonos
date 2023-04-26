#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct zuo
{double x;
double y;
double r,p;
};
int cmp(const void* a,const void* b)
{ double r1,r2,p1,p2; struct zuo m,n;
 m=*((struct zuo*)a);
 n=*((struct zuo*)b);
  if(m.p>n.p) return 1;
  else if (m.p<n.p) return -1;
  else if (m.p==n.p)
  {if(n.r>m.r) return 1;
  else return -1;}
  }
int main()
{int T,n,i,j; struct zuo s[10100]; double pi=3.141592,t;
    scanf("%d",&T);
for(i=0;i<T;i++)
{scanf("%d",&n);
 for(j=0;j<n;j++)
 {scanf("%lf %lf\n",&s[j].x,&s[j].y);
     
   s[j].r=sqrt(s[j].x*s[j].x+s[j].y*s[j].y);
   t=atan2(s[j].y,s[j].x);
   if(t<0)
   s[j].p=t+2*pi;
   else s[j].p=t;}
  qsort(s,n,sizeof(s[0]),cmp);
  printf("case #%d:\n",i);
  for(j=0;j<n;j++)
  printf("(%.4lf,%.4lf)\n",s[j].r,s[j].p);
}
    
}