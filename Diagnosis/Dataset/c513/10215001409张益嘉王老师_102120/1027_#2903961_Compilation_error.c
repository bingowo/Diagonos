#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
    double x,y;
    double ro,thr;
}point;

int cmp(const void*a,const void*b)
{
    point aa=*((point*)a);
    point bb=*((point*)b);

    if(aa.thr>bb.thr) return 1;
    else if(aa.thr<bb.thr) return -1;
    else
    {
        if(aa.ro>bb.ro) return -1;
        else return 1;
    }
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int n,j;
        point dian[1500];
        memset(dian,0,1500*sizeof(point));
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lf%lf",&dian[j].x,&dian[j].y);

            dian[j].ro=sqrt(((dian[j].x)*(dian[j].x))+((dian[j].y)*(dian[j].y)));


            if(dian[j].x==0) dian[j].thr=M_PI/2.0;
            else dian[j].thr=atan(dian[j].y/dian[j].x);
            if(dian[j].thr<0) dian[j].thr+=M_PI;
            //printf("TEST test 直角坐标dian[%d]=(%.4lf,%.4lf)\n",j,dian[j].x,dian[j].y);
            //printf("TEST test 极的坐标dian[%d]=(%.4lf,%.4lf)\n",j,dian[j].ro,dian[j].thr);
        }
        qsort(dian,n,sizeof(point),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
        {

            printf("(%.4lf,%.4lf)\n",dian[j].ro,dian[j].thr);
        }
    }
    return 0;
}
