#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    while(n != 0)
    {
        double p, q;
        p = (double)n * log10((double) n);
        p = p - (int)p;
        q = pow(10, p);
        if(q<1) q++;
        printf("%d\n", (int)q);
        scanf("%d", &n);
    }
    return 0;
}
