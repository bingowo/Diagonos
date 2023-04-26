#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned long long int llu;
llu comb(llu n,llu m)
{
    llu ret = n-m;
    return ret;
}

int main(void){
    llu n,m;
    scanf("%llu %llu",&m,&n);
    printf("%llu",comb(n, m));
    return 0;
}
