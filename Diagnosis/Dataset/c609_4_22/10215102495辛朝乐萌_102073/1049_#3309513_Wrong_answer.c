#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define len 1000

int main()
{
    long long int a,b;
    while (scanf("%lld %lld",&a,&b)!=EOF){
        printf("%lld\n",a-b);
    }
    return 0;
}