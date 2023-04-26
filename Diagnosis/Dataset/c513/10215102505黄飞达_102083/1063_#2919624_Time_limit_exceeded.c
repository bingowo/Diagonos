#include<stdio.h>
#define ll long long

int main(){
    ll x, y;
    scanf("%lld %lld", &x, &y);
    ll res = 0;
    while (y!=0){
        res += (x/y)*y*4;
        x %= y;
        if (x<y){
            int temp = x;
            x = y;
            y = temp;
        }
    }
    printf("%lld\n", res);
    return 0;
}