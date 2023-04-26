#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
#define ll long long
#define ull unsigned long long

typedef struct point{
    ll x, y;
}point;

ull myabs(ll a){
    if (a < 0) a = -a;
    return a;
}

ull mypow(ll a, ll n){
    ull ans = 1;
    while(n){
        if(n&1)     
            ans *= a;  
        a *= a;        
        n >>= 1;       
    }
    return ans;
}

int cmp(const void*a, const void*b){
    point* x = (point*)a;
    point* y = (point*)b;
    ull xx = myabs(x->x), yx = myabs(y->x), xy = myabs(x->y), yy = abs(y->y);
    if (xx+xy != yx+yy) return xx+xy > yx+yy ? -1 : 1;

    if (x->x != y->x) return x->x > y->x ? 1 : -1;
    else return x->y > y->y ? 1 : -1;
}

int main(){
    int n = 0;
    scanf("%d", &n);
    point parr[101];
    for (int i = 0; i < n; i++){
        point p0;
        scanf("%lld %lld", &p0.x, &p0.y);
        parr[i] = p0;   
    }
    qsort(parr, n, sizeof(point), cmp);
    ull first = myabs(parr[0].x-parr[1].x) + myabs(parr[0].y - parr[1].y);
    if (first < myabs(parr[0].x-parr[1].x)) printf("18446744073709551616\n");
    else printf("%llu\n", first);
    
    ll count = 0;
    for (int i = 0; i < n-1; i++){
        ull mdis = myabs(parr[i].x-parr[i+1].x)+myabs(parr[i].y - parr[i+1].y);
        if (mdis == 0){
            printf("mdis=0 continue");
            continue;
        } 
        if (mdis%2 != 0){
            for (int j = 0; j <= 62; j++){
                if (j == 62){   //oj test
                    printf("i=%d j=62: %llu %llu\n", i, mypow(2, j), mypow(2, j+1));
                    printf("mdis:%llu\n", mdis);
                }
                if (mypow(2, j) <= mdis && mdis <= mypow(2, j+1)) {
                    printf("add63？\n");
                    count += j+1;
                    break;
                }
            }
            if (mypow(2, 63) < mdis && mdis <= mypow(2, 64)-1) count += 64;
        }
        else break;
    }
    printf("%lld\n", count);
    return 0;
}