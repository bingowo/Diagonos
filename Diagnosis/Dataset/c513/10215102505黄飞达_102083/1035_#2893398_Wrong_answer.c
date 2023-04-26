#include<stdio.h>
#include<stdlib.h>
#define ll long long

typedef struct yuanzhu{
    ll r, h;
}yz;

int cmp(const void*a, const void*b){
    yz* x = (yz*)a;
    yz* y = (yz*)b;
    return x->h*x->r > y->h*y->r ? -1 : 1;
}

int main(){
    ll n, m;
    scanf("%lld %lld", &n, &m);
    yz yzarr[1001];
    for (int i = 0; i < n; i++){
        yz yz0;
        scanf("%d %d", &yz0.r, &yz0.h);
        yzarr[i] = yz0;
    }
    qsort(yzarr, n, sizeof(yz), cmp);
    ll res = 0;
    for (int i = 0; i < n; i++){
        res = yzarr[i].r*yzarr[i].r + yzarr[i].r*yzarr[i].h*2;
        ll count = 0, tempres = res;
        for (int j = 0; j < n; j++){
            if (j == i) continue;
            if (yzarr[j].r <= yzarr[i].r) tempres += yzarr[j].r*yzarr[j].h*2;
            count++;
            if (count == m-1) break;
        }
        if (tempres > res) res = tempres;
    }
    printf("%lld\n", res);
    return 0;
}