#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define pi 3.1415926
typedef struct dot
{
    double x;
    double y;
    double p;
    double ang;
}DOT;
int cmp(const void*a,const void *b)
{
    DOT a1=*(DOT*)a;
    DOT b1=*(DOT*)b;
    if(a1.ang!=b1.ang)return a1.ang>b1.ang?1:-1;
    else return a1.p>b1.p?-1:1;
}
int main()
{
    int T,n;scanf("%d",&T);DOT *a=NULL;
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        scanf("%d",&n);
        a=(DOT*)malloc(sizeof(DOT)*n);
        for(int m=0;m<n;m++){
            scanf("%lf %lf",&a[m].x,&a[m].y);
            a[m].p=sqrt(a[m].x*a[m].x+a[m].y*a[m].y);
            a[m].ang=atan2(a[m].y,a[m].x);
            if(a[m].ang<0)a[m].ang=2*pi+a[m].ang;
            qsort(a,n,sizeof(DOT),cmp);
        }
        for(int m=0;m<n;m++){
            printf("(%.4lf,%.4lf)\n",a[m].p,a[m].ang);
        }
        free(a);
    }
    return 0;
}
