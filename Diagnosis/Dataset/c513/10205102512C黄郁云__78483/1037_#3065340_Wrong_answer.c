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
    int ttl = 0;
    int pick  = 0;
    scanf("%d %d",&ttl,&pick);
    for(int i = 0 ; i < ttl;i++){
        scanf("%lld",&ini[i]);//初始的每一項數據
    }
    qsort(ini,ttl,sizeof(ini[0]),cmp);
    sum[0] = ini[0];
    for(int i = 1;i <ttl;i++){
        sum[i] = sum[i-1]+ini[i];//累加和
    }
    long long int min = 1000000000000000000;
    long long pick_long = (long long)pick;
    for(int i = 0; i <ttl;i++){
        long long int sumback_pick = sum[i+pick-1]-sum[i];
        long long int min_temp = (pick_long-1)*ini[i]-sumback_pick;
        if(min_temp < min){
            min = min_temp;
        }
    }
    printf("%lld",min);
}