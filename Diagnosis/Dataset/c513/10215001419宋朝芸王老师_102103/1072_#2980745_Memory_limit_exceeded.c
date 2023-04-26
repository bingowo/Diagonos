#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long uabs(long long int a){
    return (unsigned long long)(a);
}

void path(long long int m, long long int n, int i){
    if(m == 0 && n == 0) return;
    long long step = pow(2,i-1);

    if(abs(m) > abs(n)){
        if(m > 0){
            path(m-step,n,i-1);
            printf("E");
        }
        else{
            path(m+step,n,i-1);
            printf("W");
        }
    }
    else{
        if(n > 0){
            path(m,n-step,i-1);
            printf("N");
        }
        else{
            path(m,n+step,i-1);
            printf("S");
        }
    }

}

int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);

    /***case_1***/
    if(x == 0 && y == 0){
        printf("0");
        return 0;
    }

    unsigned long long manhatten = uabs(x) + uabs(y);
    /***case_2***/
    if(manhatten % 2 == 0){
        printf("-1");
        return 0;
    }

    int i = 0;
    while(pow(2,i) < manhatten) i++;
    printf("%d\n",i);

    path(x,y,i);

    return 0;
}
