#include <stdio.h>
#include <stdlib.h>

long long int ini[1000010];
long long int sum[1000010];

int cmp(const void*a,const void *b){
    long long *A = (long long*)a;
    long long *B = (long long *)b;
    if (*A != *B){
        if(*A>*B){
            return -1;
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}


int main(){
    long long int ttl = 0;
    long long int pick  = 0;
    scanf("%lld %lld",&ttl,&pick);
    for(int i = 0 ; i < ttl;i++){
        scanf("%lld",&ini[i]);//初始的每一項數據
    }
    qsort(ini,ttl,sizeof(ini[0]),cmp);
    sum[0] = ini[0];
    for(int i = 1;i <ttl;i++){
        sum[i] = sum[i-1]+ini[i];//累加和
    }
    long long int min = 99999999999999999;
    for(int i = 0; i <ttl-pick;i++){
        long long int sumback_pick = sum[i+pick-1]-sum[i];
        long long int min_temp = (pick-1)*ini[i]-sumback_pick;
        if(min_temp < min){
            min = min_temp;
        }
    }
    printf("%lld",min);
}
