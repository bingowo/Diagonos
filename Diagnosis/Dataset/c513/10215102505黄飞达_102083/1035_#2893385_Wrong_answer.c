#include<stdio.h>
#include<stdlib.h>
#define ll long long

typedef struct yuanzhu{
    int r, h;
}yz;

int cmp(const void*a, const void*b){
    yz* x = (yz*)a;
    yz* y = (yz*)b;
    return - x->h*x->r + y->h*y->r;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    yz yzarr[1001];
    for (int i = 0; i < n; i++){
        yz yz0;
        scanf("%d %d", &yz0.r, &yz0.h);
        yzarr[i] = yz0;
    }
    qsort(yzarr, n, sizeof(yz), cmp);
    ll res = 0;
    int maxr = yzarr[0].r;
    for (int i = 0; i < m; i++) {
        res += 2 * yzarr[i].r * yzarr[i].h;
        if (yzarr[i].r > maxr) maxr = yzarr[i].r;
    } 
    res += maxr*maxr;
    for (int i = m; i < n; i++){
        if (yzarr[i].r >= maxr){
            int tempres = res + yzarr[i].r*yzarr[i].r + 2*yzarr[i].r*yzarr[i].h - maxr*maxr - 2*yzarr[m-1].r*yzarr[m-1].h;
            if (res < tempres) res = tempres;            
        }
    }
    printf("%lld\n", res);
    return 0;
}