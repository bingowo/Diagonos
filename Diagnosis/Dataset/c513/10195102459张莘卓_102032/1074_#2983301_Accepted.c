#include <stdio.h>
#include <string.h>
#define mod 1000000007

int main()
{
    int T;
    scanf("%d",&T);
    for(int k=0; k<T; ++k) {
        char s[101];
        scanf("%s",s);
        long long a[101][210] = {1}, sum;
        int len = strlen(s);
        for(int i=0; i<len; ++i) {
            sum = 0;
            for(int j=i; j<len; ++j) {
                sum = (sum*10 + s[j]-'0') % 210 ;
                for(int w=0; w<210; ++w)
                    if(a[i][w]) {
                        a[j+1][(w+sum)%210] += a[i][w];
                        a[j+1][(w+sum)%210] %= mod;
                        if(i) {
                            a[j+1][(w-sum+210)%210] += a[i][w];
                            a[j+1][(w-sum+210)%210] %= mod;
                        }
                    }
            }
        }
        sum = 0;
        for(int w=0; w<210; ++w) {
            if(w%2==0 || w%3==0 || w%5==0 || w%7==0)
                sum = (sum + a[len][w]) % mod;
        }
        printf("%d\n",(int)sum);
    }
    return 0;
}
