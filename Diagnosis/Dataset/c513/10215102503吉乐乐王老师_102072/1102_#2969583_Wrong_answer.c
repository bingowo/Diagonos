#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef unsigned long long int ull;
typedef long long int ll;
int main(){
    ull *func=(ull*)malloc(sizeof(ull)*10000000);
    func[0]=0;
    for(int i=1;i<10000000;i++)func[i]=i*8+func[i-1];
    ull n;
    scanf("%llu",&n);
    if(n==0){printf("(0,0)");return 0;}
    ll x,y;
    ull now;
    for(int i=9999999;i>=0;i--){
        if(n==func[i]){x=i;y=x;now=func[i];break;}
        else if(n>func[i]){x=i;y=x+1;now=func[i]+1;break;}
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