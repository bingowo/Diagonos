#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define PI 3.1415
typedef struct jizuobiao
{
    double len;
    double ang;
}P;
void change(P *p,double x,double y)
{
    p->len=pow(x*x+y*y,0.5);
    p->ang=atan(y/x);
    if(p->ang<=0)
    {
        if(y<0) p->ang=(2*PI+p->ang);
        else if(x<0) p->ang=(PI+p->ang);
    }
    else
    {
        if(x<0 || y<0) p->ang=(PI+p->ang);
    }
}
int cmp(P *a,P *b)
{
    if(a->ang!=b->ang) return (a->ang-b->ang);
    else return (a->len-b->len);
}
int main()
{
    int T=0;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        int N=0;
        scanf("%d\n",&N);
        P *p=(P*)malloc(sizeof(P)*(N+1));
        for(int j=0;j<N;j++)
        {
            double x,y;
            scanf("%f %f",&x,&y);
            change(p+j,x,y);
        }
        qsort(p,p+N,sizeof(p[0]),cmp)
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
            printf("(%.4f,%.4f)\n",p[j].len,p[j].ang);
        }
    }
    return 0;
}