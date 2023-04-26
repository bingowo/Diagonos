#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>



int main(void){
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        double n,m;
        scanf("lf %lf",&n,&m);
        printf("case #%d:\n",i);
        printf("%lf\n",n/m);
    }
    return 0;
}
