#include<stdio.h>
int main()
{
    int n;
    double dis,spd,rem,cpl,time=0;
    scanf("%lf\n%d\n",&dis,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf %lf",&cpl,&spd);
        rem=dis-cpl;
        double tmp=rem/spd;
        if(tmp>time) time=tmp;
    }
    printf("%.6lf",dis/time);
}