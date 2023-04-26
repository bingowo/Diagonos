#include<stdio.h>
int main(){
    unsigned long long int x,y;
    scanf("%llu %llu",&x,&y);
    unsigned long long int ret=0;
    while(x>0&&y>0){
        if(x>y){
            unsigned long long int t;
            t=x;x=y;y=t;
        }
        do{
            ret+=x*4;
            y-=x;
        }while(y>=x);
    }
    printf("%llu",ret);
}