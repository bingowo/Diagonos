#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int main(){
    unsigned long long int func[1000]={0};
    for(int i=1;i<1000;i++)func[i]=i*8+func[i-1];
    unsigned long long int n;
    scanf("%llu",&n);
    int x,y;
    unsigned long long int now;
    for(int i=0;i<1000;i++){
        if(n<func[i]){x=i-1;now=func[i-1]+1;break;}
    }
    y=x+1;
    int side=2*x+2;
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
        for(int i=1;i<side;i++){
            if(now==n){flag=1;break;}
            else{x++;now++;}
        }
    }
    if(!flag){
        for(int i=1;i<side;i++){
            if(now==n){flag=1;break;}
            else{y++;now++;}
        }
    }
    printf("(%d,%d)",x,y);
}