#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
    double x,y,p,o;
}POINT;
int compar(const void *p1,const void *p2);
void myPrint(POINT* point,int N);
int main()
{
    int T,N,i;
    double x,y,o;
    POINT *point;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        point=(POINT*)malloc(N*sizeof(POINT));
        for(i=0;i<N;i++)
        {
            scanf("%lf %lf",&point[i].x,&point[i].y);
            x=point[i].x;
            y=point[i].y;
            point[i].p=sqrt(x*x+y*y);
            if(x>=0&&y>=0)
                o=atan(y/x);
            else if(x<=0&&y>=0)
                o=atan(y/x)+acos(-1);
            else if(x<=0&&y<=0)
                o=atan(y/x)+acos(-1);
            else
                o=atan(y/x)+2*acos(-1);
            point[i].o=o;
        }
        qsort(point,N,sizeof(POINT),compar);
        myPrint(point,N);
    }
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0;
    POINT *a=(POINT*)p1,*b=(POINT*)p2;
    if(a->o<b->o)
        flag=-1;
    else if(a->o>b->o)
        flag=1;
    else
    {
        if(a->p>b->p)
            flag=-1;
        else
            flag=1;
    }
    return flag;
}
void myPrint(POINT* point,int N)
{
    static int tim=0;
    int i;
    printf("case #%d:\n",tim++);
    for(i=0;i<N;i++)
    {
        printf("(%.4lf,%.4lf)\n",point[i].p,point[i].o);
    }
}
