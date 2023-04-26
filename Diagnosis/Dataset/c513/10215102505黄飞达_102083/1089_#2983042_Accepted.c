#include<stdio.h>
#define ll long long

int main(){
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++){
        printf("case #%d:\n", t);
        ll a, b, n;
        scanf("%lld %lld %lld", &a, &b, &n);
        ll res=1;
        ll M=1;
        for (int i=1; i<=n; i++) M*=10;
        for (int i=1; i<=b; i++){
            res*=a;
            res%=M;
        }
        M/=10;
        while(M>res+1){
            printf("0");
            M/=10;
        }
        printf("%lld\n", res);
    }   
    return 0;
}