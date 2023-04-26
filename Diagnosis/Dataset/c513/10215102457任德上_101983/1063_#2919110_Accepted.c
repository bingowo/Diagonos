#include<stdio.h>
int main(){
    long long int x,y,x1,y1,sum=0,n;
    scanf("%lld%lld",&x,&y);
    x1=x>y?x:y;
    y1=x>y?y:x;
    while(x1!=y1){
        if(x1%y1==0){
            n=x1/y1;
            sum+=n*4ll*y1;
            x1=y1=0;
        }
        else{
            n=x1/y1;
            sum+=n*4ll*y1;
            x1=x1-n*y1;
            n=x1;
            x1=y1;
            y1=n;
        }
    }
    sum+=4ll*x1;
    printf("%lld",sum);
    return 0;
}
