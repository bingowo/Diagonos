#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 550
#define BigNUm 10007
#define Max 1000000

typedef long long lli;



int main(){
    int d,n;scanf("%d%d",&d,&n);
    double tMin=0,tmp=0;
    for(int i=0;i<n;i++){
        int k;
        double s;
        scanf("%d%lf",&k,&s);
        tmp=(d-k)/s;
        if(tmp>tMin) tMin=tmp;
    }
    printf("%.6f",d/tMin);


    return 0;

}
