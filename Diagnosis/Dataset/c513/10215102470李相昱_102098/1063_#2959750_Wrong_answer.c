#include <stdio.h>
long long int Sum(long long int x,long long int y){
    long long int ret;
    if(x==y){
        ret=4*y;
    }else{
        if(x-y>y){
            ret = 4*y+ Sum(x-y,y);
        } else{
            ret = 4*y+ Sum(y,x-y);
        }
    }
    return ret;
}
int main() {
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    printf("lld", Sum(x,y));
    return 0;
}
