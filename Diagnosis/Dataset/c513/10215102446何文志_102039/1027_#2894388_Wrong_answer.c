#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3.1415926
typedef struct Point
{
    double x;
    double y;
}point;



double MygetRou(point Pt)
{
    double ans = sqrt(Pt.x*Pt.x+Pt.y*Pt.y);
    return ans;
}
double MygetTheta(point Pt)
{
    double ans = atan(Pt.y/Pt.x);
    if(Pt.x>0)
    {
        if(Pt.y>=0){return ans;}
        else{return 2*Pi+ans;}
    }
    else if(Pt.x<0)
    {
        return Pi+ans;
    }
    else if(Pt.x == 0)
    {
        if(Pt.y>=0){return ans;}
        else{return 2*Pi+ans;}
    }
    return ans;
}

int cmp(const void *a,const void *b)
{
    point A = *(point*)a,B = *(point*)b;
    double rA = MygetRou(A),thetaA = MygetTheta(A);
    double rB = MygetRou(B),thetaB = MygetTheta(B);
    //printf("rA = %f,thetaA = %f,rB= %f,thetaB = %f\n",rA,thetaA,rB,thetaB);
    if(fabs(thetaA-thetaB)>0.000001){return thetaA>thetaB;}
    else{return rA<rB;}
}



int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        int N = 0;
        scanf("%d",&N);
        point pt[N];memset(pt,0,N*sizeof(point));
        for(int j = 0;j<N;j++)
        {
            scanf("%lf%lf",&pt[j].x,&pt[j].y);
        }

        qsort(pt,N,sizeof(pt[0]),cmp);
        printf("case #%d:\n",i);
        for(int k = 0;k<N;k++)
        {
            double r = MygetRou(pt[k]);
            double theta = MygetTheta(pt[k]);
            printf("(%.4f,%.4f)\n",r,theta);
        }
    }
    return 0;
}

