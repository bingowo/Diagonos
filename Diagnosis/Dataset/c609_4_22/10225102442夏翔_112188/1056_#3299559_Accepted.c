//1056 (easy)
#include<stdio.h>
int main(){
    int T, m, n;
    long long sum1, sum2;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        printf("case #%d:\n", t);
        scanf("%d %d", &m, &n);
        sum1 = 1; sum2=1;
        if(n>m/2) n = m-n;
        for(int i=0; i<n; i++){
            sum1 *= m-i;
            if(sum1%(i+1)==0) sum1 /= i+1; //避免高精度
            else sum2 *= i+1;
        }
        printf("%lld\n", sum1/sum2);
    }

    return 0;
}