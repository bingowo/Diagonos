#include<stdio.h>
#define ll long long

ll C(int m, int n){
    ll temp1=1, temp2=1;
    for (int i=1; i<=n; i++) {
        temp1 *= m-n+i;
        temp2 *= i;
        if (temp1%temp2==0) {
            temp1/=temp2;
            temp2=1;
        }
    }
    return temp1 / temp2;
}
int main(){
    int T, m, n;
    scanf("%d", &T);
    for (int t=0; t<T; t++){
        scanf("%d %d", &m, &n);
        printf("case #%d:\n", t);
        printf("%lld\n", C(m, n));
    }
    return 0;
}

// m!/n!(m-n)!