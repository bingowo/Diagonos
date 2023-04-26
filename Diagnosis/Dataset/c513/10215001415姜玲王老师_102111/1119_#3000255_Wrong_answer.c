#include <stdio.h>
#include <stdlib.h>

int main()
{
    double d;
    int n;
    double v1,v2,d1,d2;
    double t1,t2=0.0,v;
    scanf("%f",&d);
    scanf("%d",&n);
    for(int t=1;t<n;t++)
    {
    scanf("%f",&v1);
    scanf("%f",&d1);
    t1=(d-d1)/v1;
    if(t1>t2){t2=t1;v2=v1;d2=d1;}
    }
    v=d/t2;
    printf("%.6lf",v);


}
