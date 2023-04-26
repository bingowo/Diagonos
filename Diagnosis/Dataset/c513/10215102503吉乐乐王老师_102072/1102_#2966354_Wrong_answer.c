#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef unsigned long long int ull;
typedef long long int ll;
int main(){
    ull func[1000]={0};
    for(int i=1;i<1000;i++)func[i]=i*8+func[i-1];
    ull n;
    scanf("%llu",&n);
    ll x,y;
    ull now;
    for(int i=0;i<1000;i++){
        if(n<func[i]){x=i-1;now=func[i-1]+1;break;}
    }
    y=x+1;
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