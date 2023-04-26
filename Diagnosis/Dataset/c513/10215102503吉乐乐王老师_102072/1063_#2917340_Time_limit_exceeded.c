#include<stdio.h>
int main(){
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    unsigned long long int ret=0;
    while(x>0&&y>0){
        if(x>y){
            long long int t;
            t=x;x=y;y=t;
        }
        do{
            ret+=x*4;
            y-=x;
        }while(y>=x);
    }
    printf("%lld",ret);
}