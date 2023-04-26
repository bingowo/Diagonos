#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>


int main(void){
    double n,m;
    scanf("%lf %lf",&m,&n);
    printf("%.7lf",comb(n, m));
    return 0;
}
