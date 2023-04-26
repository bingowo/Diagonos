#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct{long long x;long long y;unsigned long long m;}point;
int cmp(const void*a,const void*b)
{point p1=*(point*)a;
point p2=*(point*)b;
if(p1.m>p2.m) return -1;
if(p1.m<p2.m)  return 1;
if(p1.x>p2.x)   return 1;
if(p1.x<p2.x)   return -1;
if(p1.y>p2.y)    return 1;
return -1;
}
unsigned long long Abs(long long a,long long b)
{unsigned long long t;
t=a-b;
if(t<0) return -t;
else return t;
}
int step(point a,point b)
{unsigned long long distance;
int k=0;
distance=Abs(a.x,b.x)+Abs(a.y,b.y);
if(distance==0) return 0;
if(distance%2==0) return -1;
while(distance)
{k++;
distance/=2;}
return k;

}
int main()
{int n,Step=0;
unsigned long long max;
scanf("%d",&n);
point a[100];
for(int i;i<n;i++)
{scanf("%lld%lld",&a[i].x,&a[i].y);
a[i].m=Abs(a[i].x,0)+Abs(a[i].y,0);
}
qsort(a,n,sizeof(a[0]),cmp);
max=Abs(a[0].x,a[1].x)+Abs(a[0].y,a[1].y);
if(max<Abs(a[0].x,a[1].x)) printf("18446744073709551616\n");
else printf("%llu\n",max);
for(int i=0;i<n-1;i++)
{if(step(a[i],a[i+1])==-1) break;
Step+=step(a[i],a[i+1]);}
printf("%d",Step);

}
