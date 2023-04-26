#include<stdio.h>

#define ll long long
#define N 10000

typedef struct{
    int cnt, v[N];
}BIG;

BIG change(ll a){
    BIG res = {0, {0}};
    do{
        res.v[res.cnt++] = a % 10;
        a /= 10;
    }while(a);
    int lo = 0, hi = res.cnt - 1;
    while(lo <= hi){
        int temp = res.v[lo];
        res.v[lo++] = res.v[hi];
        res.v[hi--] = temp;
    }
    return res;
}

ll mpow(ll a, ll b){
    ll res = 1;
    while(b--){
        res *= a;
    }
    return res;
}

ll mix(BIG s){
    ll temp = 0;
    for (int i = s.cnt - 2; i >= 0; i--)
        temp += s.v[i];
    ll res = temp % 9;
    return res? 9 - res: 0;
}

ll min(ll a, ll b){
    return a > b? b: a;
}

ll cal(BIG bign){
    ll res = 0;
    for (ll i = 0; i < bign.cnt - 1; i++){
        if (bign.v[i] == 9){
            for (ll j = i; i < bign.cnt; j++)
                bign.v[j] = 8;
        }
        res += bign.v[i] * mpow(9LL, bign.cnt - i - 2) * 8LL;
    }
    ll left = min(bign.v[bign.cnt - 1], 8);
    res += left + 1;
    if (mix(bign) <= left) res--;
    return res;
}


int main(){
    ll a, b;
    while(~scanf("%lld%lld", &a, &b))
        printf("%lld\n", cal(change(b)) - cal(change(a-1)));
    return 0;
}