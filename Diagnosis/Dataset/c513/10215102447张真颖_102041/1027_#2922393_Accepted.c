#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415926

int cmp(const void*a,const void*b)
{
    double *pa=*(double(*)[2])a,*pb=*(double(*)[2])b;
    double anglea=atan2(pa[1],pa[0]),angleb=atan2(pb[1],pb[0]);
    if(anglea<0) anglea=2*pi+anglea;
    if(angleb<0) angleb=2*pi+angleb;
    if(anglea>angleb) return 1;
    else if(anglea<angleb) return -1;
    else
    {
        if((pa[0]*pa[0]+pa[1]*pb[1])>(pb[0]*pb[0]+pb[1]*pb[1])) return -1;
        else if((pa[0]*pa[0]+pa[1]*pb[1])<(pb[0]*pb[0]+pb[1]*pb[1])) return 1;
        return 0;
    }

}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N=0;
        double pos[1000][2]={0};
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%lf%lf",&pos[i][0],&pos[i][1]);
        qsort(pos,N,sizeof(pos[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<N;i++)
        {
            double angle=atan2(pos[i][1],pos[i][0]);
            if(angle<0) angle=2*pi+angle;
            printf("(%.4lf,%.4lf)\n",sqrt(pos[i][0]*pos[i][0]+pos[i][1]*pos[i][1]),angle);
        }
    }
    return 0;
}