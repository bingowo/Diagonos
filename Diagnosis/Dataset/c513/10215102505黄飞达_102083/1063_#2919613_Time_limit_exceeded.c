#include<stdio.h>
#define ll long long
ll func(ll x, ll y){//处理xy边长的田地
    if (x==0 || y==0) return 0;
    if (x<y){
        int temp = x;
        x = y;
        y = temp;
    }
    return 4*y + func(x-y, y);
}

int main(){
    ll x, y;
    scanf("%lld %lld", &x, &y);
    ll res = func(x, y);
    printf("%lld\n", res);
    return 0;
}