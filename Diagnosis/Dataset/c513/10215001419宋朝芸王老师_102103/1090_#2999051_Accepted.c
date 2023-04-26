#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    while(scanf("%d",&n) && n != 0){
        double a;
        int res;
        a = log10(n) * n;
        a = a - (int)a;
        res = pow(10,a);
        printf("%d\n",res);
    }
    return 0;
}
