#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    double d;
    scanf("%lf",&d);
    int n;
    scanf("%d",&n);
    double dis0,v0;
    scanf("%lf%lf",&dis0,&v0);
    double vmax=dis0*v0/(d-dis0)+v0;
    for(int i=1;i<n;i++)
    {
       double dis,v;
       scanf("%lf%lf",&dis,&v);
       double z=dis*v/(d-dis)+v;
       vmax=(vmax>z)?z:vmax;
    }
    printf("%lf",vmax);
    return 0;
}
