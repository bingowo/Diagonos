#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main()
{
    double time = 0.0;
    int d, n;
    scanf("%d %d",&d, &n);
    for(int i=0; i<n; ++i) {
        int k, s;
        scanf("%d %d",&k, &s);
        if(1.0*(d-k)/s > time)
            time = 1.0 * (d-k) / s;
    }
    printf("%.6f\n",d/time);
    return 0;
}
