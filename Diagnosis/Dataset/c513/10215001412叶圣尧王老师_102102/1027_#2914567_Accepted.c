#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct st 
{
    double x;
    double y;
    double p;
    double q;
};

int cmp(const void*a,const void*b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(c->q!=d->q)return (c->q>d->q)? 1:-1;
    
    else return d->p-c->p;
}
double get(double x,double y)
{
    double z;
    if(x>0&&y>=0)z=atan(y/x);
    else if(x>0&&y<0)z=atan(y/x)+3.1415926*2;
    else if(x<0)z=atan(y/x)+3.1415926;
    else if(y>0)z=3.1415926/2;
    else if(y<0)z=3.1415926*3/2;
    return z;
}


int main()
{
    int T;scanf("%d",&T);int N,i=0,j;
    while(i<T)
    {
        printf("case #%d:\n",i);
        scanf("%d",&N);struct st s[N];
        for(j=0;j<N;j++)
        {
            scanf("%lf%lf",&s[j].x,&s[j].y);
            s[j].p=sqrt(s[j].x*s[j].x+s[j].y*s[j].y);
            s[j].q=get(s[j].x,s[j].y);
        }
        qsort(s,N,sizeof(s[0]),cmp);
        for(j=0;j<N;j++)
            printf("(%.4f,%.4f)\n",s[j].p,s[j].q);
        i++;
    }
}