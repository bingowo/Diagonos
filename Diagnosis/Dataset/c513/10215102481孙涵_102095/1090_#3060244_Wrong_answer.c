#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    long long int N,result;
    double x,y;
    scanf("%lld",&N);
    while(N != 0){
        x = x * log10(N);
        y = (long long) x;
        x = x - y;
        result = (long long)pow(10,x);
        printf("%d\n",result);
        scanf("%lld",&N);
    }
    return 0;
}
