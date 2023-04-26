#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define ull unsigned long long

typedef struct point{
    ll x, y;
}point;

ull myabs(ll a){
    if (a < 0) a = -a;
    return a;
}

int cmp(const void*a, const void*b){
    point* x = (point*)a;
    point* y = (point*)b;
    ll xx = abs(x->x), yx = abs(y->x), xy = abs(x->y), yy = abs(y->y);
    if (xx+xy != yx+yy) return xx+xy > yx+yy ? -1 : 1;
    if (x->x != y->x) return x->x > y->x ? 1 : -1;
    else return x->y > y->y ? 1 : -1;
}

int main(){
    int n;
    scanf("%d", &n);
    point parr[101];
    for (int i = 0; i < n; i++){
        point p0;
        scanf("%lld %lld", &p0.x, &p0.y);
        parr[i] = p0;   
    }
    qsort(parr, n, sizeof(point), cmp);

    printf("%llu\n", myabs(parr[0].x-parr[1].x)+myabs(parr[0].y - parr[1].y));
    
    ll count = 0;
    for (int i = 0; i < n-1; i++){
        ull mdis = myabs(parr[i].x-parr[i+1].x)+myabs(parr[i].y - parr[i+1].y);
        if (mdis%2 != 0){
            for (int j = 0; j < 64; j++){
                if (pow(2, j) <= mdis && mdis <= pow(2, j+1)) {
                    count += j+1;
                    break;
                }
            }
        }
        else break;
    }
    printf("%lld\n", count);
    return 0;
}