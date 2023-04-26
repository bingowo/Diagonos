#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define N 1001
#define Pi 3.14159265
typedef struct{double p,angle;}point;

int compare(const void*a,const void*b)
{
    point c=*(point*)a;
    point d=*(point*)b;
    if(c.angle<d.angle)return -1;
    if(c.angle>d.angle)return 1;
    else return d.p-c.p;
}


int main()
{
   int n,i,j,cas;
   double x,y;
   point *s;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&cas);
       s=(point*)malloc(cas*sizeof(point));
       for(j=0;j<cas;j++)
       {
           scanf("%lf%lf",&x,&y);
           s[j].p=sqrt(pow(x,2)+pow(y,2));
           if(y>=0)
           {
               if(x>0)s[j].angle=atan(y/x);
               else if(x<0)s[j].angle=atan(y/x)+Pi;
               else if(x==0)s[j].angle=Pi/2;
           }
           else
           {
               if(x<0)s[j].angle=atan(y/x)+Pi;
               else if(x>0)s[j].angle=atan(y/x)+2*Pi;
               else if(x==0)s[j].angle=3*Pi/2;
           }
       }
       qsort(s,cas,sizeof(point),compare);
       printf("case #%d:\n",i);
       for(j=0;j<cas;j++)printf("(%.4lf,%.4lf)\n",s[j].p,s[j].angle);
   }
   free(s);
   return 0;
}
