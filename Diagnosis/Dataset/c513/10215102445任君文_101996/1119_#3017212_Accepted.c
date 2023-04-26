#include<stdio.h>
#include<stdlib.h>
double mymax(double x, double y)
{
    if(x>y)
        return x;
    else
        return y;
}
int main()
{
    double Max=0;
    int d,n;
    int i;
    double v;
    int s;
    scanf("%d",&d);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%lf",&s,&v);
        if(i==0)
            Max=(d-s)/v;
        else
        {
            Max=mymax(Max,(d-s)/v);
        }
    }
    printf("%.6lf",d/Max);
    return 0;
}