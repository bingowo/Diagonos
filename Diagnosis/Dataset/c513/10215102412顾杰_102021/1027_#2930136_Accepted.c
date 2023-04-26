#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct {double x;double y;}point;
int cmp(const void*a,const void*b)
{
    point c=*(point*)a,d=*(point*)b;
    if(fabs(c.y-d.y)>=0.000000001)return c.y-d.y<0?-1:1;
    return c.x-d.x>0?-1:1;
}
int main()
{
   int i,j,n,k;
   point a[1000];
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&k);
       double x,y;
       for(j=0;j<k;j++){scanf("%lf%lf",&x,&y);a[j].x=sqrt(x*x+y*y);a[j].y=atan(y/x);if(x<0)a[j].y+=3.1415926;if(x>=0&&y<0)a[j].y+=2*3.1415926;}
       qsort(a,k,sizeof(a[0]),cmp);
       printf("case #%d:\n",i);
       for(j=0;j<k;j++)printf("(%.4f,%.4f)\n",a[j].x,a[j].y);
   }
}
