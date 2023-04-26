#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MOD = 1e9+7;


long long func(char * a)
{
    int len = strlen(a);
    if(len == 1)    return 1;
    if(len == 2)    return ((a[0] == a[1]) ? 1 : 4);

    long long r = 1;
    if(a[0] != a[1])    r = 2;
    for(int i = 1; i < len - 1; i++)
    {
        long long c = 1;
        if(a[i] != a[i - 1])    c++;
        if(a[i] != a[i + 1] && a[i - 1] != a[i + 1])    c++;
        r = (r * c) % MOD;
    }
    if(a[len - 1] != a[len - 2]) r = (r * 2) % MOD;
    return r;

}

int main()
{
    char s[1200];
    long long func(char * a);
    scanf("%s",s);
    printf("%lld",func(s));
}
