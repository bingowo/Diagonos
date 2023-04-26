#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 19
#define B 2333

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        long long int dec = 0;
        scanf("%lld",&dec);

        int cnt = 0;
        int store[M] = {'0'};
        while(dec > 0){
            store[cnt++] = dec % B;
            dec = dec / B;
        }
        printf("%d",store[--cnt]);
        while(cnt > 0) printf(" %d",store[--cnt]);
        printf("\n");

    }
    return 0;
}
