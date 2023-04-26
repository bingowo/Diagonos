#include <stdio.h>
#include <stdlib.h>
int pow2(int n){
    if(n==0) return 1;
    return 2*pow2(n-1);
}
int main(){
    long long x, y;
    scanf("%lld %lld", &x, &y);
    int temp=abs(x)+abs(y);
    int flag=0;
    for(int i=1; i<=40; i++){
        int ret=pow2(i);
        if(ret-1-temp<0) continue;
        if((ret-1-temp)%2==0){
            printf("%d\n", i);
            flag = 1;
            break;
        }
    }
    if(flag==0) printf("%d\n", -1);
    return 0;
}