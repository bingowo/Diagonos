#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N=0;
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        double x=0.0;
        x=log10(N)*N;
        x-=(long long int)x;
        int a=pow(10,x);
        printf("%d\n",a);
    }
    return 0;
}
