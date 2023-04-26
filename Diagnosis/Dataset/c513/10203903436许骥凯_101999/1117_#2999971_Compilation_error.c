#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define ll long long
#define MAX(a, b) a > b? a: b
#define MIN(a, b) a > b? b: a

int main(){
    ll ox, oy; scanf("%lld%lld", &ox, &oy);
    int n; scanf("%d", &n);
    ll min_dis = LLONG_MAX; 
    ll min_x = LLONG_MAX, min_y = LLONG_MAX;
    for (int i = 0; i != n; i++){
        ll x, y; scanf("%lld %lld", &x, &y);
        ll dis = MAX(llabs(x - ox), llabs(y - oy));
        if (dis < min_dis){
            min_dis = dis;
            min_x = x; min_y = y;
        }
        else if (dis == min_dis){
            if (x < min_x) min_x = x, min_y = y;
            else if (x == min_x && y < min_y) min_x = x, min_y = y;
        }
    }
    printf("%lld\n%lld %lld\n", min_dis, min_x, min_y);
    return 0;
}