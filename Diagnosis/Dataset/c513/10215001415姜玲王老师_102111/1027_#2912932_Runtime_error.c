#include <stdlib.h>
#include<math.h>
struct point{double l;double degree;};
double degree(double a,double b)
{if(a==0&&b==0) return 0;
if(a==0&&b>0)  return acos(0);
if(a==0&&b<0)  return 3*acos(0);
if(a>0&&b>=0) return atan(b/a);
if(a<0&&b<=0) return atan(b/a)+2*acos(0);
 if(a>0&&b<0) return atan(b/a)+4*acos(0);
 if(a<0&&b>0) return atan(b/a)+2*acos(0);
}
int cmp(const void*a,const void*b)
{struct point*p1=(struct point*)a;
 struct point*p2=(struct point*)b;
 if(p1->degree>p2->degree) return 1;
 if(p1->degree<p2->degree) return -1;
 if(p1->l>p2->l) return -1;
 if(p1->l<p2->l) return 1;
}
int main()
{int t,n;
double a[100][2],temp;
scanf("%d",&t);
struct point p[100];
for(int i=0;i<t;i++)
{printf("case #%d:\n",i);
scanf("%d",&n);
for(int j=0;j<n;j++)
{scanf("%lf %lf",&a[j][0],&a[j][1]);
temp=pow(a[j][0],2)+pow(a[j][1],2);
p[j].l=sqrt(temp);
p[j].degree=degree(a[j][0],a[j][1]);
}
qsort(p,n,sizeof(p[0]),cmp);
for(int k=0;k<n;k++)
printf("(%.4lf,%.4lf)\n",p[k].l,p[k].degree);}}
