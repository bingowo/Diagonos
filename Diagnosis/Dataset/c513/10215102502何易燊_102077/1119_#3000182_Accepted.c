#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d; scanf("%d",&d);
    int n; scanf("%d",&n);
    double maxt = 0;
    for (int i=0;i<n;i++)
    {
        int k,s; scanf("%d %d",&k,&s);
        double t = (d-k)*1.0/s;
        if (t>maxt) maxt = t;
    }
    printf("%.6lf",d/maxt);
    return 0;
}