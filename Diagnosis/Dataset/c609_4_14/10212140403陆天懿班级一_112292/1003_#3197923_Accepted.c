#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;

int pros;
ll mo=2333;
ll c;
void Fun(ll c){
    if(c){
        Fun(c/mo);
        printf("%d ",c%mo);
    }
}

int main(){
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%lld",&c);
        if(c)
            Fun(c);
        else
            printf("0");
        printf("\n");
    }
    return 0;
}

