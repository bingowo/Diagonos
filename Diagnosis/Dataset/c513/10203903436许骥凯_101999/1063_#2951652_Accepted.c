#include<stdio.h>

long long int cal(long long int l, long long int m){
    if (!(l % m)) return 4 * l;
    return cal(m, l%m) + 4 * m * (l / m); 
} 

int main(){
    long long int l, m; scanf("%lld%lld", &l, &m);
    printf("%lld\n", cal(l, m));
    return 0;
}