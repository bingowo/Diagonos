#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
unsigned long long int bs (long long int x)
{ if(x>0) return x;
else return -x;
    
}
struct get
{ int power,coe;
};
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
{int n,i,j,a,b,k; struct point p[1000];  unsigned long long int man,step,dx,dy,max;
struct get p1[1000],p2[1000];
scanf("%d\n",&n);
for(i=0;i<n;i++)
{scanf("%lld %lld",&p[i].x,&p[i].y);
  p[i].d=bs(p[i].x)+bs(p[i].y);
}
qsort(p,n,sizeof(p[0]),cmp);  
dx=bs(p[0].x-p[1].x);
dy=bs(p[0].y-p[1].y);
man=bs(p[0].x-p[1].x)+bs(p[0].y-p[1].y);
if(bs(p[0].x-p[1].x)>man) printf("18446744073709551616\n");
else
printf("%llu\n",man);
step=0;
for(j=0;j<n-1;j++)
{   if(p[j].x == p[j + 1].x && p[j].y == p[j + 1].y)
     continue;
    dx=bs(p[j].x-p[j+1].x);
    dy=bs(p[j].y-p[j+1].y);
    man=dx+dy;
    if(dx%2!=dy%2)
     { if(man>(1ull<<63))
         { step+=64;
           continue;
         }
        for (k=1;k<=64;k++)
        {if(dx<=(1ull<<k)&&dx>=(1ull<<(k-1)))
         {p1[j].power=k;
          p1[j].coe=dx/pow(2,k-1);
         }
         if(dy<=(1ull<<k)&&dy>=(1ull<<(k-1)))
         {p2[j].power=k;
          p2[j].coe=dy/pow(2,k-1);
         }
        }
         
         
     }
     max=p1[j].power>p2[j].power?p1[j].power:p2[j].power;
     step+=max;
     if(p1[j].power==p2[j].power)
     step++;
   else 
   {break;}
}
printf("%llu",step);
}