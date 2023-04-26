#include <stdio.h>
#include <stdlib.h>

int main()
{
    double d;
    scanf("%lf",&d);
    int n;
    scanf("%d",&n);
    double t=0;
    for(int i=0;i<n;i++)
    {
        double k,s;
        scanf("%lf %lf",&k,&s);
        double l=(d-k)/s;
        if(t<l) t=l;
    }
    printf("%.6f",d/t);
}
