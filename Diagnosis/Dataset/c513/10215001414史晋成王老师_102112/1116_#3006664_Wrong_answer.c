#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
unsigned long long int bs (long long int x)
{ if(x>0) return x;
else return -x;
    
}
struct point
{ long long int x,y;
unsigned long long int d;
};
int cmp(const void*a,const void*b)
{ struct point p,q;
p=*((struct point*)a);
q=*((struct point*)b);
if(q.d>p.d) return 1;
else if (q.d<p.d) return -1;
else if ((q.d==p.d)&&(p.x!=q.x))
{if (p.x>q.x) return 1;
    else if (p.x<q.x) return -1;
}
else if ( p.y>q.y) return 1;
else if  (p.y<q.y) return -1;
}

int main()
{int n,i,j,a,b,k; struct point p[1000]; 
unsigned long long int man,step; long long int x,y;
scanf("%lld %lld",&x,&y);
man=bs(x)+bs(y);
step=0;
    if(man%2)
     { for (k=1;k<=64;k++)
        if(man<(1ull<<k))
         {step+=k;
         }
        if(man>(1ull<<63))
         { step+=64;
             
         }
         
         
     }


if(step==0) printf("-1");
else
printf("%llu",step);
}