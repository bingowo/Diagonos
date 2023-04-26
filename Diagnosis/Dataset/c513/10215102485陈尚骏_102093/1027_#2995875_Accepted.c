#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>

typedef struct{
    double r;
    double theta;
}R;

int dcmp(double a,double b)
{
    if(a==b) return 0;
    if(a<b) return -1;
    else return 1;
}

int cmp(const void *a,const void *b)
{
    const R *r1=a,*r2=b;
    int c=dcmp(r1->theta,r2->theta);
    if(c==0) return -dcmp(r1->r,r2->r);
    else return c;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        R v[10000];
        R *p=v;
        for(int j=0;j<n;j++)
        {
            double a,b;
            scanf("%lf %lf",&a,&b);
            double theta=atan2(b,a);
            p->r=hypot(a,b);
            p->theta=theta<0?theta+atan(1.0)*8:theta;
            p++;
        }
        qsort(v,n,sizeof(R),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<n;k++)
            printf("(%.4lf,%.4lf)\n",v[k].r,v[k].theta);
    }
    return 0;
}
