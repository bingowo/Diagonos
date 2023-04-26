#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;
    while(scanf("%d",&N)) {
        if(N == 0) break;
        double a = N * log10(N) - (int)(N * log10(N));
        printf("%d\n",(int)pow(10, a));
    }
    return 0;
}
