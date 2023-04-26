#include <stdio.h>
#include <string.h>

const int MOD = 1e9+7;
typedef long long ll;

int main()
{
    char w[1000];
    scanf("%s",w);
    int len = strlen(w);
    if(len == 1)
        printf("1\n");
    if(len == 2)
        printf("%d\n",(w[0] == w[1]) ? 1 : 4);

    ll r = 1;
    if(w[0] != w[1])    r = 2;
    for(int i = 1; i < len - 1; i++)
    {
        ll c = 1;
        if(w[i] !=w[i - 1])
            c++;
        if(w[i] != w[i + 1] && w[i - 1] != w[i + 1])
            c++;
        r = (r * c) % MOD;
    }
    if(w[len - 1] != w[len - 2])
        r = (r * 2) % MOD;
    printf("%lld\n",r);
    return 0;
}
