#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define pi 3.1415926535
typedef struct
{
    double p;
    double o;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.o!=s2.o)
    {
        if(s1.o>s2.o)
            return 1;
        else
            return -1;
    }
    else
    {
        if(s1.p>s2.p)
            return-1;
        else
            return 1;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
       int n;
       scanf("%d",&n);
       node a[n];
       for(int i=0;i<n;i++)
       {
           double x,y;
           scanf("%lf %lf",&x,&y);
           double j=atan2(y,x);
           if(j<0)j=2*pi+j;
           a[i].o=j;
           a[i].p=sqrt(pow(x,2)+pow(y,2));
       }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<n;i++)
            printf("(%.4lf %.4lf)\n",a[i].p,a[i].o);
    }
}
