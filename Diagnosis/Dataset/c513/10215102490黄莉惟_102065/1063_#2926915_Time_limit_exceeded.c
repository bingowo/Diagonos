#include<stdio.h>
#include<string.h>
#include <stdlib.h>
long long int GCD(long long int x,long long int y){
    long long int sum=0;
    while(x!=0||y!=0){
        if(x>y&&x%y==0){
            sum=(x/y)*4*y;
        }else if(x<y&&y%x==0){
            sum=(y/x)*4*x;
        }else{
            if(x>y){
                x-=y;
                sum=sum+4*y;
            }else if(x<y){
                y-=x;
                sum+=4*x;
            }else{
                sum+=4*x;
                x-=x;
                y-=y;
            
            }
        }
        
    }
    return sum;
}
int main(){
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",GCD(x,y));
}