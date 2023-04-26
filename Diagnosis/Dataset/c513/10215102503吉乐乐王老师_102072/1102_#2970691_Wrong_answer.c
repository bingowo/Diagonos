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
    ll x,y;
    ull now;
    ull func,pre;
    for(int i=0;i<10000000;i++){
        func=(2*i+1)*(2*i+1);
        if(n==func){x=i;y=i+1;now=func;break;}
        else if(func>n){x=i-1;y=i;now=pre;break;}
        pre=func;
    }
    ll side=2*x+2;
    int flag=0;
    for(int i=1;i<=side-1;i++){
        if(now==n){flag=1;break;}
        else {x--;now++;}
    }
    if(!flag){
        for(int i=1;i<=side;i++){
            if(now==n){flag=1;break;}
            else{y--;now++;}
        }
    }
    if(!flag){
        for(int i=1;i<=side;i++){
            if(now==n){flag=1;break;}
            else{x++;now++;}
        }
    }
    if(!flag){
        for(int i=1;i<=side;i++){
            if(now==n){flag=1;break;}
            else{y++;now++;}
        }
    }
    printf("(%lld,%lld)",x,y);
}