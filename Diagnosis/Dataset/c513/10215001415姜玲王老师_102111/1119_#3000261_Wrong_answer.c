#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d;
    int n;
    int v1,v2,d1,d2;
    double t1,t2=0,v;
    scanf("%d",&d);
    scanf("%d",&n);
    for(int t=0;t<n;t++)
    {
    scanf("%d",&v1);
    scanf("%d",&d1);
    t1=(d-d1)*1.0/v1*1.0;
    if(t1>t2){t2=t1;v2=v1;d2=d1;}
    }
    v=d*1.0/t2;
    printf("%.6lf",v);


}
