#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    long long int n;
    scanf("%lld",&n);
    if(n==0){
        printf("(0,0)");
    }else{
        long long int round=sqrt(n);
        long long int x,y;
        while(n-round*round<0)round--;
        long long int d=n-round*round;
        if(round%2){
            round=(round+1)/2;
            x=round-1;
            y=round;
            if(d>2*round-1){
                x=-round;
                y-=(d-2*round+1);
            }else x-=d;
        }else{
            round/=2;
            x=-round;
            y=-round;
            if(d>2*round){
                x=round;
                y+=(d-2*round);
            }else x+=d;
        }
        printf("(%lld,%lld)",x,y);
    }
    
    return 0;
}
