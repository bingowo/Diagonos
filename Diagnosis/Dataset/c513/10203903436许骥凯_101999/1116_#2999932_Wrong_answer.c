#include<stdio.h>
#include<math.h>
#define ll long long
int main(){
    ll a, b; scanf("%lld%lld", &a, &b);
    ll sum = llabs(a) + llabs(b);
    if (!sum) printf("0\n");
    else if (!(sum % 2)) printf("-1\n");
    else{
        ll res = 1;
        for (int i = 0; i != 100; i++){
            if (res < sum && res * 2 >= sum){
                printf("%d\n", i);
                break;
            }
            res *= 2;
        }
    }
    return 0;
}