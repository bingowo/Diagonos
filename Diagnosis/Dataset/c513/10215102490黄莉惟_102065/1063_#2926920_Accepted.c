#include<stdio.h>
#include<string.h>
#include <stdlib.h>
long long int GCD(long long int x,long long int y){
    long long int sum=0;
    if(x==1) return 4*y;
    if(y==1) return 4*x;
    if(x%y==0) return (x/y)*4*y;
    while(x!=0||y!=0){
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
    return sum;
}
int main(){
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",GCD(x,y));
    
}