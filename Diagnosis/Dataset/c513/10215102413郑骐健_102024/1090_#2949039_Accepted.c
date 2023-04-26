#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

    double m;
    while(scanf("%lf",&m),m>0.1)
{
    double z = log10(m);
    z = m*z;
    z -=(long long)z;
    int b = pow(10,z);
    printf("%d\n",b);
}
    return 0;
}
