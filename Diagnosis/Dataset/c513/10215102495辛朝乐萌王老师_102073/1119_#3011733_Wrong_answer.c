#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#define LEN 110



int main()
{
    int d,n;
    scanf("%d %d",&d,&n);
    double maxsec=0;
    double dis,v;
    for (int i=0; i<n; i++) {
        scanf("%lf %lf",&dis,&v);
        if ((d-dis)/v>maxsec) {
            maxsec=(d-dis)/v;
        }
        printf("%.6lf",d / maxsec);
    }
    return 0;
}
