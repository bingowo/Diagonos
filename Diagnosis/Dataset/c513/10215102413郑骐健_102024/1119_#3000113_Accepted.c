#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>


typedef struct
{
    double t;
    double l;
}car;

int cmp(const void*p1,const void*p2)
{
    car p3 = *(car*)p1;
    car p4 = *(car*)p2;
    if (p3.l <p4.l)return -1;
    else return 1;
}

int main()
{
    double last;
     scanf("%lf",&last);
     int n;
     scanf("%d",&n);
     car s[2000];
     for(int i=0;i<n;i++)
     {
         double l,v;
         scanf("%lf%lf",&l,&v);
         s[i].l = last-l;
         s[i].t = s[i].l/v;
     }
     qsort(s,n,sizeof(car),cmp);
     double time =0;
     for(int q =0;q<n;q++)
     {
         if(s[q].t>time)time =s[q].t;
     }
     printf("%.6lf",last/time);
    return 0;
}
