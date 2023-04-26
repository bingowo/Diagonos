#include <stdio.h>
#define abs(x) (x>0?x:-x)
int main(){
    long long x,y;
    scanf("%lld%lld",&x,&y);
    long long sum = abs(x)+abs(y);
    int k = 1,pow = 2;
    if((abs(x)&1)^(abs(y)&1)) {
        while(sum>pow){
            k++;
            pow*=2;
        }
        printf("%d",k);
    }
    else printf("-1");
    return 0;
}