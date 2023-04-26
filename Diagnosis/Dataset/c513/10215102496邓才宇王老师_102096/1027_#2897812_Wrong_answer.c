#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
    double x;
    double y;
    double r;
    double p;
}MA;
int cmp(const void *p1,const void *p2)
{
    MA* a=p1;
    MA* b=p2;
    if((*a).p>(*b).p) return 1;
    else if((*a).p<(*b).p) return -1;
    else
    {
        if((*a).r>(*b).r) return -1;
        else  if((*a).r<(*b).r) return 1;
        else return 0;
    }
}
int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
   {
       int N;
       scanf("%d",&N);
        MA a[1000];
       for(int j=0;j<N;j++)
       {
           scanf("%lf %lf",&a[j].x,&a[j].y);
           a[j].r=sqrt(a[j].x*a[j].x+a[j].y*a[j].y);
           if(a[j].x>0&&a[j].y>0) a[j].p=atan(a[j].y/a[j].x);
           if(a[j].x<0&&a[j].y>0) a[j].p=atan(a[j].y/a[j].x)+3.14159;
           if(a[j].x<0&&a[j].y<0) a[j].p=atan(a[j].y/a[j].x)+3.14159;
           if(a[j].x>0&&a[j].y<0) a[j].p=atan(a[j].y/a[j].x)+3.14159*2;
           if(a[j].x==0&&a[j].y>0) a[j].p=3.14259/2;
           if(a[j].x==0&&a[j].y<0) a[j].p=(3.14259/2)*3;
           if(a[j].x==0&&a[j].y==0) a[j].p=0;
           if(a[j].x>0&&a[j].y==0) a[j].p=0;
           if(a[j].x<0&&a[j].y==0) a[j].p=3.14259;
       }
        qsort(a,N,sizeof(MA),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
        {
            printf("(%.4f %.4f)\n",a[k].r,a[k].p);
        }
   }
}
