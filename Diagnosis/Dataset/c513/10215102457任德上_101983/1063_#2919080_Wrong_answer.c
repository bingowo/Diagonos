#include<stdio.h>
int main(){
    long long int x,y,x1,y1,sum=0,n;
    scanf("%lld%lld",&x,&y);
    x1=x,y1=y;
    while(x1!=y1){
        if(x1>y1){
            n=x1/y1;
            sum+=n*4ll*y1;
            x1-=y1;
        }
        else{
            n=y1/x1;
            sum+=n*4ll*x1;
            y1-=x1;
        }
    }
    sum+=4ll*x1;
    printf("%lld",sum);
    return 0;




}