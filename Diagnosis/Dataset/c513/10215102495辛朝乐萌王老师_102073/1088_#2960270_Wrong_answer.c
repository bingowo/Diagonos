#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned long long int llu;
llu comb(llu n,llu m)
{
    llu ret = 1;
    for (int i=1; i<=n; i++) {
        ret =ret*(m-i+1)/i;
    }
    return ret;
}

int main(void){
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        llu n,m;
        scanf("%llu %llu",&n,&m);
        printf("case #%d:\n",i);
        printf("%llu",comb(n, m));
    }
    return 0;
}
