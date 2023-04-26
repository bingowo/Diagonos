#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int compar(const void *p1,const void *p2);
int main()
{
    int T,N,i,tim=0;
    double x,y,p,o;
    scanf("%d",&T);
    while(T--)
    {
        printf("case #%d:\n",tim++);
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%lf %lf",&x,&y);
            p=sqrt(x*x+y*y);
            o=atan(y/x);
            printf("(%.4lf,%.4lf)\n",p,o);
        }
    }
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0;
    int *a=(int*)p1,*b=(int*)p2;
    if(*a<*b)
        flag=-1;
    else
        flag=1;
    return flag;
}
