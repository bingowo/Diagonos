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
{int n,i,j,a,b,k; struct point p[1000];  unsigned long long int man,step,dx,dy;
scanf("%d\n",&n);
for(i=0;i<n;i++)
{scanf("%lld %lld",&p[i].x,&p[i].y);
  p[i].d=bs(p[i].x)+bs(p[i].y);
}
qsort(p,n,sizeof(p[0]),cmp);  
man=bs(p[0].x-p[1].x)+bs(p[0].y-p[1].y);
if(bs(p[0].x-p[1].x)>man) printf("18446744073709551616\n");
else
printf("%llu\n",man);
step=0;
for(j=0;j<n-1;j++)
{  man=bs(p[j].x-p[j+1].x)+bs(p[j].y-p[j+1].y);
    if(man%2)
     { for (k=1;k<=64;k++)
        if(man<(1ull<<k))
         {step+=k;
          break;
         }
        if(man>(1ull<<63))
         { step+=64;
           break;
             
         }
         
         
     }
   else 
   {break;}
}
printf("%llu",step);
}