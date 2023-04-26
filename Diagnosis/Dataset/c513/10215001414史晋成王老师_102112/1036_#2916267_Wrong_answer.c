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
{int n,i,j,a,b; struct point p[1000];  long long int man,step;
scanf("%d\n",&n);
for(i=0;i<n;i++)
{scanf("%lld %lld",&p[i].x,&p[i].y);
  p[i].d=labs(p[i].x)+labs(p[i].y);
}
qsort(p,n,sizeof(p[0]),cmp);  
man=labs(p[0].x-p[1].x)+labs(p[0].y-p[1].y);
printf("%lld",man);
}