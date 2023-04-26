#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef unsigned long long int ull;
typedef long long int ll;
int main(){
    ull n;
    scanf("%llu",&n);
    if(n==0){printf("(0,0)");return 0;}
    ull func,now;
    ll x=0,y=1;
    int flag=0;
    ll i=1;
    for(;i<1000000;i++){
        func=i*i;
        if(func>n)break;
    }
    if(i%2){x=-i/2;y=-i/2;now=(i-1)*(i-1);}
    else {x=i/2-1;y=i/2;now=(i-1)*(i-1);}
    if(x>=0){
        for(;x>-(i-1);x--){
            if(now==n){flag=1;break;}
            else now++;
        }
        if(!flag){
            for(;y>-(i-1);y--){
                if(now==n){flag=1;break;}
                else now++;
            }
        }
    }
    else{
        if(!flag){
            for(;x<(i-2);x++){
                if(now==n){flag=1;break;}
                else now++;
            }
        }
        if(!flag){
            for(;y<i-1;y++){
                if(now==n){flag=1;break;}
                else now++;
            }
        }
    }
    printf("(%lld,%lld)",x,y);
}