#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    double t,v1,len,max,v,d,s;
    scanf("%lf",&len);
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%lf%lf",&d,&v);
        s = len - d;
        t = s/v;
        max = max > t? max: t;
    }
    v1 = len/max;
    printf("%lf",v1);
    return 0;
}
