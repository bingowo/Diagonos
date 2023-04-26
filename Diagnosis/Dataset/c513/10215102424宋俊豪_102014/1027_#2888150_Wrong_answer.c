#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define pi 3.1415926
typedef struct
{
    double t1;
    double p;
    double ti;
} list;
int cmp(const void *a,const void *b)
{
    list *ax=(list*)a;
    list *bx=(list*)b;
    if (fabs((ax->ti)-(bx->ti))>0.00001)
    {
        if((ax->ti)-(bx->ti)>0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {

        if(bx->t1-ax->t1>0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    int n;
    double x,y;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int n1=0;
        scanf("%d",&n1);
        list *t=(list*)malloc(sizeof(list)*n1);
        for (int j=0; j<n1; j++)
        {
            scanf("%lf %lf",&x,&y);
            t[j].t1=x*x+y*y;
            t[j].p=sqrt(x*x+y*y);
            t[j].ti=atan2(y,x);
            if (t[j].ti<0)
                t[j].ti+=2*pi;
        }
        qsort(t,n1,sizeof(t[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0; i<n1; i++)
            printf("(%.4f,%.4f)\n",t[i].p,t[i].ti);
        free(t);
    }
    return 0;
}