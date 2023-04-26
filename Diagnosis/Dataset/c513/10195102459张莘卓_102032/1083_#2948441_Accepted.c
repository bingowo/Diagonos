#include <stdio.h>
#define mod 1000000000

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int N, cnt = 0;
        scanf("%d",&N);
        long long temp = 1;
        for(int i=1; i<=N; ++i) {
            temp = temp * i % mod;
            while(temp && temp % 10 == 0) {
                ++cnt;
                temp /= 10;
            }
        }
        printf("case #%d:\n%d\n",j,cnt);
    }
    return 0;
}