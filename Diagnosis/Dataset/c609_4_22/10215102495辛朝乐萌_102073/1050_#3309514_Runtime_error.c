#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define len 1000

int main()
{
    float a,b;
    while (scanf("%lf %lf",&a,&b)!=EOF){
        printf("%lf\n",a-b);
    }
    return 0;
}