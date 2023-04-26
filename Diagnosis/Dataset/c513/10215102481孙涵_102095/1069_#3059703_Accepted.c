#include <stdio.h>
#include <stdlib.h>

int count=0;

long long int compute(long long int N);

long long int put(long long int N);

int main()
{
    long long int n;
    scanf("%lld",&n);
    printf("%d %lld",count,compute(n));
    return 0;
}

long long int compute(long long int N){
    long long int c[100],i,j,flag,n,q;
    n = N;
    q = 0;
    for(i = 0; n > 0; i++){
        c[i] = n % 10;
        n = n / 10;
    }
    for(j = 0, flag = 0; j < i; j++){
        if(c[j] != c[i - 1 - j]){
            flag = 1;
        }
    }
    if (flag == 0){
        return N;
    }
    count++;
    for(j = 0; j < i; j++){
        q = q * 10 + c[j];
    }
    return compute(N + q);
}
