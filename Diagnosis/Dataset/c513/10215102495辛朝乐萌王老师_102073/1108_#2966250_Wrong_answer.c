#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>



int main(void){
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int n,m;
        scanf("d %d",&n,&m);
        printf("case #%d:\n",i);
        printf("%lf\n",(double)(n/m));
        printf("5-5");
    }
    return 0;
}
