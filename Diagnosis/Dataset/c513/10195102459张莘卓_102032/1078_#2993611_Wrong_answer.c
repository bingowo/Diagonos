#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int v;
    int fz;
    int fm;
} Number;
Number a[1002];
int n;

void gcd(int* pa, int* pb);
int pourWater(int s, int p);
int lowestWater(int s, int base, int lp, int rp);
void full(Number s, int lp, int rp, int dir);
Number fullSub(Number s, int lp, int rp, int dir);
void fullFinal(Number s, int lp, int rp, int dir);

int main()
{
    int s, pos;
    scanf("%d %d %d",&n, &s, &pos);
    a[0].v = a[n+1].v = 1000009;
    a[0].fz = a[n+1].fz = 0;
    a[0].fm = a[n+1].fm = 1;
    for(int i=1; i<=n; ++i) {
        scanf("%d",&a[i].v);
        a[i].fz = 0;  a[i].fm = 1;
    }
    while(s > 0) {
        s = pourWater(s, pos);
    }
    for(int i=1; i<=n; ++i) {
        if(a[i].fz){
            if(a[i].v) printf("%d+",a[i].v);
            printf("%d/%d",a[i].fz, a[i].fm);
        }else printf("%d",a[i].v);
        printf("%s",i<n?" ":"\n");
    }
    return 0;
}

void gcd(int* pa, int* pb) {
    int a = *pa, b = *pb;
    while(b) {
        int t = b; b = a % b; a = t;
    }
    *pa /= a;  *pb /= a;
}

int pourWater(int s, int p) {
    int lv=0, rv=0, lp=p, rp=p, v, base=a[p].v;
    for(int i=p-1; i>=0; --i) {
        lp = i;
        if(a[i].v > base) break;
        lv += base - a[i].v;
    }
    for(int i=p+1; i<=n+1; ++i) {
        rp = i;
        if(a[i].v > base) break;
        rv += base - a[i].v;
    }
    v = lv + rv;
    if(v == 0) {
        return lowestWater(s,base, lp, rp);
    }else if(v <= s) {
        for(int i=lp+1; i<rp; ++i)
            a[i].v = base;
        return s - v;
    }else {
        Number half;
        half.v = s/2; half.fz = s%2; half.fm = 2;
        if(half.v >= lv) {
            for(int i=lv+1; i<p; ++i) a[i].v = base;
            half.v = s - lv; half.fz = 0; half.fm = 1;
            full(half, p, rp, 1);
        }else if(half.v >= rv) {
            for(int i=p+1; i<rp; ++i) a[i].v = base;
            half.v = s - rv; half.fz = 0; half.fm = 1;
            full(half, p, lp, -1);
        }else {
            full(half, p, lp, -1);
            full(half, p, rp, 1);
        }
        return 0;
    }
}

int lowestWater(int s, int base, int lp, int rp) {
    int lim = a[lp].v < a[rp].v ? a[lp].v : a[rp].v;
    int wid = rp - lp -1;
    if((lim-base)*wid <= s) {
        for(int i=lp+1; i<rp; ++i)
            a[i].v = lim;
        return s - wid*(lim-base);
    }else {
        int v=s/wid+base, fz=s%wid, fm=wid;
        gcd(&fz, &fm);
        for(int i=lp+1; i<rp; ++i) {
            a[i].v = v;
            a[i].fz = fz; a[i].fm = fm;
        }
        return 0;
    }
}

void full(Number s, int lp, int rp, int dir) {
    while(s.v || s.fz) {
        s = fullSub(s, lp, rp, dir);
    }
}

Number fullSub(Number s, int lp, int rp, int dir) {
    int tp = lp;
    while(tp!=rp && a[tp].v>=a[tp+dir].v) tp += dir;
    while(tp!=rp && a[tp].v<=a[tp+dir].v) tp += dir;
    int v=0, lim = a[lp].v<a[tp].v?a[lp].v:a[tp].v;
    for(int i=lp; i!=tp+dir; i+=dir) //question ???
        if(a[i].v < lim) v += lim - a[i].v;
    if(s.v >= v) {
        for(int i=lp+dir; i!=tp; i+=dir)
            if(a[i].v < lim) a[i].v = lim;
        s.v -= v;
        return s;
    }else {
        fullFinal(s, lp, tp, dir);
        Number ret; ret.v=ret.fz=0; ret.fm=1;
        return ret;;
    }
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void fullFinal(Number s, int lp, int rp, int dir) {
    int arr[1002], t = 0;
    for(int i=lp; i!=rp+dir; i+=dir) arr[t++] = a[i].v;
    qsort(arr, t, sizeof(int), cmp);
    int cnt = 0;
    for(int i=1; i<t; ++i) {
        int c = (arr[i] - arr[i-1]) * i;
        if(s.v < c) {
            cnt = i; break;
        }else s.v -= c;
    }
    int fz = s.v*s.fm + s.fz;
    int fm = s.fm * cnt;
    int zs = arr[cnt-1] + fz/fm;
    fz %= fm;
    gcd(&fz, &fm);
    for(int i=lp; i!=rp+dir; i+=dir) {
        if(a[i].v <= zs) {
            a[i].v = zs; a[i].fz = fz; a[i].fm = fm;
        }
    }
}
