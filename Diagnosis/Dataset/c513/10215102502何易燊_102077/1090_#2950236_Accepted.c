#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        double f = n*log10(n)-floor(n*log10(n));
        f = pow(10,f);
        printf("%.0lf\n",floor(f));
    }
    return 0;
}