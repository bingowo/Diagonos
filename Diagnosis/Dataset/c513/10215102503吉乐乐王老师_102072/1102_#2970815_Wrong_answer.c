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
    ll i=0;
    for(;i<10000000;i++){
        func=i*i;
        if(func>=n)break;
    }
    ll x,y;
    if(i%2){x=n==func?i-2:i-4;y=x+1;now=(y+1)*(y+1);}
    else {x=n==func?-(i-2):-(i-4);y=x;now=(abs(y-2)*abs(y-2));}
    ll side=2*abs(x)+2;
    int flag=0;
    if(x>=0){
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
    }
    else{
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
    }
    printf("(%lld,%lld)",x,y);
}