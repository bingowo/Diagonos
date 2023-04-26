#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef unsigned long long int llu;
llu a,b;
int main()
{
    scanf("%llu %llu",&a,&b);
    llu c=a-b;
    printf("%llu",c);
}
