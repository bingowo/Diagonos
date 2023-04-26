#include<stdio.h>
int main(){
    long long int x0,y0,x1,y1,x,y,d1,d2,x2,y2;
    scanf("%lld%lld",&x0,&y0);
    x=x0,y=y0;
    d1=100000000000000000LL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&x1,&y1);
        x2=x1>x0?x1-x0:x0-x1;
        y2=y1>y0?y1-y0:y0-y1;
        d2=x2>y2?x2:y2;
        if(d1==d2){
            if(x1==x){
                if(y1<y)y=y1;
            }
            else if(x1<x)x=x1,y=y1;
        }
        else if(d2<d1){
            d1=d2;
            x=x1,y=y1;
        }
    }
    printf("%lld\n%lld %lld",d1,x,y);
    return 0;


}