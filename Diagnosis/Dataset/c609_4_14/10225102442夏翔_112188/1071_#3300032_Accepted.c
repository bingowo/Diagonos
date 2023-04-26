//1071 
#include <stdio.h>
#include <stdlib.h>
long long pow2(int n){
    if(n==0) return 1;
    return 2*pow2(n-1);
}
int main(){
    long long x, y;
    scanf("%lld %lld", &x, &y);
    long long temp=llabs(x)+llabs(y);  //注意llabs  abs
    int flag=0;
    if(temp==0){ //special
        printf("%d\n", 0);
        flag = 1;
    }else{
        for(int i=1; i<=50; i++){
            long long ret=pow2(i); //ret-1为走的总步数
            if(ret-1-temp<0) continue;
            if((ret-1-temp)%2==0){//多出来的步数为偶数
                printf("%d\n", i);
                flag = 1;
                break;
            }
        }
    }
    if(flag==0) printf("%d\n", -1);
    return 0;
}