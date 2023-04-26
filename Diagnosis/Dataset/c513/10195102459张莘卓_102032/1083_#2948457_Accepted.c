#include <stdio.h>
#define mod 100000

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int N, cnt = 0, temp = 1;
        scanf("%d",&N);
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