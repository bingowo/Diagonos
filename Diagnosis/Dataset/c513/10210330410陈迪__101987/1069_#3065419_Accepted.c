#include <stdio.h>
#include <stdlib.h>

int count = 0;

long long int put(long long int N)
{
    long long int c[100], i, j, flag;
    long long int n = N, Q = 0;
    for(i = 0; n > 0; i++)
    {
        c[i] = n % 10;
        n /= 10;
    }
    for(j = 0, flag = 0; j < i; j++)
        if(c[j] != c[i-1-j]) flag = 1;
    if(flag == 0) return N;
    count++;
    for(j = 0; j < i; j++)
        Q = Q * 10 + c[j];
    return put(N+Q);
}

int main()
{
    long long int n;
    scanf("%lld", &n);
    printf("%d %lld", count, put(n));
    return 0;
}
