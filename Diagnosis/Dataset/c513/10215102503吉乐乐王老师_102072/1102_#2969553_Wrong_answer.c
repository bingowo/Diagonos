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
    ll func,pre=0;
    ull now;
    for(int i=1;i<100000000;i++){
        func=i*8+pre;
        if(n==func){x=i;y=x;now=func;break;}
        else if(n<func||func<0){x=i-1;y=x+1;now=pre+1;break;}
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