#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long

typedef struct num{
    ll value, high;
}num;


int cmp(const void *a, const void *b){
    num *x = (num*)a;
    num *y = (num*)b;
    if (x->high != y->high) return x->high > y->high ? -1 : 1;
    else return y->value > x->value ? -1 : 1;
}

int main(){
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++){
        int n;
        scanf("%d", &n);
        num numarr[10001];
        for (int i = 0; i < n; i++){
            num n0;
            scanf("%lld", &n0.value);
            ll temp = n0.value, high = 0;
            while (temp){
                high = temp;
                temp /= 10;
            }
            if (high < 0) high = -high;
            n0.high = high;            
            numarr[i] = n0;;
        }
        qsort(numarr, n, sizeof(num), cmp);
        printf("case #%d:\n", t);
        for (int i = 0; i < n; i++) printf("%lld ", numarr[i].value);
        printf("\n");
    }
    return 0;
}

