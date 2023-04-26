#include<stdio.h>
#include<stdlib.h>
#define ll long long

int cmp(const void*a, const void*b){
    return *(int*)a < *(int*)b ? -1 : 1;
}

int main(){
    ll T;
    scanf("%lld", &T);
    for (ll t=0; t<T; t++){
        ll n, m;
        scanf("%lld %lld", &n, &m);
        ll oldarr[1001] = {0};
        ll newarr[500500] = {0};
        for (ll i=1; i<=n; i++) scanf("%lld", &oldarr[i]);
        ll index = 1;
        for (ll i=0; i<n; i++){//长度
            for (ll j=1; j+i<=n; j++){//起始位
                for (ll k=0; k<=i; k++){
                    newarr[index] += oldarr[j+k];
                }
                index++;
            }
        }
        qsort(newarr, index, sizeof(ll), cmp);
        printf("case #%lld:\n", t);
        for (ll i=1; i<index; i++) newarr[i] += newarr[i-1];
        for (ll i=0; i<m; i++){
            ll l, u;
            scanf("%lld %lld", &l, &u);
            printf("%lld\n", newarr[u]-newarr[l-1]);
        }
    }
    return 0;
}