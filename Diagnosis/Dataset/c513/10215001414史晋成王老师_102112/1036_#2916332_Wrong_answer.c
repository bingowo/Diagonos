#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct point
{ long long int d,x,y;
};
int cmp(const void*a,const void*b)
{ struct point p,q;
p=*((struct point*)a);
q=*((struct point*)b);
if(q.d>p.d) return 1;
else return -1;
}

int main()
{int n,i,j,a,b; struct point p[1000];  long long int man,step,o,q;
scanf("%d\n",&n);
for(i=0;i<n;i++)
{scanf("%lld %lld\n",&p[i].x,&p[i].y);
  if(p[i].x<0) o=-p[i].x; else o=p[i].x;
  if(p[i].y<0) q=-p[i].y; else q=p[i].y;
  p[i].d=o+q;
}
qsort(p,n,sizeof(p[0]),cmp); 
if(p[0].x-p[1].x<0) o=-(p[0].x-p[1].x);
else o=p[0].x-p[1].x;
if (p[0].y-p[1].y<0) q=-(p[0].y-p[1].y);
else q=(p[0].y-p[1].y);
man=o+q;
printf("%lld",man);
}