#include<stdio.h>

int isn(long long n){
    while(n>0){
        int m=n%10;
        n/=10;
        if(m==9)return 1;
    }
    return 0;
}

int main(){
    long long n;
    while(n%9==0||isn(n)==1)n++;
    printf("%lld",n);
}