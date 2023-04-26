#include<stdio.h>
#define ll long long
int main(){
    ll a, b; scanf("%lld%lld", &a, &b);
    a = a >= 0? a: -a; b = b >= 0? b: -b; 
    if (!((a + b) % 2)) printf("-1\n");
    else if (a == 0 && b == 0) printf("0\n");
    else{
        ll fac = 1;
        ll s_ab = a + b + 1;
        for (int i = 1; i != 50; i++){
            if (fac < s_ab && fac * 2 >= s_ab){
                printf("%d\n", i);
                break;
            }
            fac *= 2;
        } 
    }
    return 0;
}