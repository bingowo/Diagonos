#include<stdio.h>
int main(){
    int num;
    int p_n[10] = {0};
    int cnt = 2;
    long long int ret[120] = {0,1,1};
    for(int i = 0;i<num;i++){
        printf("case #i:\n", i);
        while(p_n[i]>cnt){
            ret[cnt+1] = ret[cnt]+ret[cnt-1];
            cnt++;
        }
        printf("%lld\n", ret[i]);
    }
    return 0;
}