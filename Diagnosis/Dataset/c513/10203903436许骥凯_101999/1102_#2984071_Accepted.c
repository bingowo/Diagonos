#include<stdio.h>
#include<math.h>

#define ll long long

int main(){
    ll n; scanf("%lld", &n);
    ll t = 0;
    while((t+1) * (t+1) <= n) t++;
    if (t * t == n){
        if (t % 2) printf("(%d,%d)\n", (t - 1) / 2, (t - 1) / 2 + 1);
        else printf("(%d,%d)\n", - t / 2, - t / 2);
    }
    else{
        ll x, y;
        if (t % 2){
            x = (t - 1) / 2, y = (t - 1) / 2 + 1;
            if (n - t * t > t) x -= t, y -= n - t - t * t;
            else x -= n - t * t;  
        }
        else{
            x = - t / 2, y = - t / 2;
            if (n - t * t > t) x += t, y += n - t - t * t;
            else x += n - t * t;
        }
        printf("(%lld,%lld)\n", x, y);
    }
}