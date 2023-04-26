#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int N;
    while (1)
    {
        scanf("%d",&N);
        if (N==0) break;
        double t=N*log10(N);
        long long tt=t;
        t-=tt;
        int result=pow(10,t);
        printf("%d\n",result);
    }
    return 0;
}
