#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dis;
    int v;
    double t;
}car;

int cmp(const void*a,const void*b)
{
    car aa=(*(car*)a);
    car bb=(*(car*)b);
    if(aa.t>bb.t) return -1;
    else if(bb.t>aa.t) return 1;
    else return 0;
}

int main()
{
    int d,i,n;
    scanf("%d",&d);
    scanf("%d",&n);
    car *p=(car*)malloc(sizeof(car)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].dis,&p[i].v);
        p[i].t=(double)(d-p[i].dis)/p[i].v;
    }
    qsort(p,n,sizeof(car),cmp);
    double re=d/p[0].t;
    printf("%.6f\n",re);

}
