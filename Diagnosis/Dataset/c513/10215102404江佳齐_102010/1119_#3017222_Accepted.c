#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    double d,k,s,v;
    double max=-1;
    scanf("%lf",&d);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf",&k,&s);
        v=(d-k)/s;
        if(v>max) max=v;
    }
    printf("%.6f",d/max);
    return 0;
}
