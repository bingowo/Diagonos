//1064;
#include <stdio.h>
#include <string.h>
long long f(long long x, long long y){
    if(y==0) return 0;
    int ret = x/y; //最多能有几个以y为边长的正方形
    return 4*y*ret+f(y, x-y*ret);
}
int main(){
    long long x, y, ans;
    scanf("%lld %lld", &x, &y);
    ans = f(x, y);
    printf("%lld\n", ans);
    return 0;
}