#include<stdio.h>
#include<string.h>
const int MOD = 1e9+7;
typedef long long ll;
ll func(char *a)
{
    int len = strlen(a); 
    if(len == 1)    return 1;
    if(len == 2)    return ((a[0] == a[1]) ? 1 : 4);
    ll r = 1;
    if(a[0] != a[1])    r = 2;
    for(int i = 1; i < len - 1; i++)
    {
        ll diff = 1;
        if(a[i] != a[i - 1])    diff++;
        if(a[i] != a[i + 1] && a[i - 1] != a[i + 1])    diff++;
        r = (r * diff) % MOD;
    }
    if(a[len - 1] != a[len - 2]) r = (r * 2) % MOD;
    return r;

}


int main()
{
   char s[1001];
    scanf("%s",&s);
    printf("%lld\n",func(s));
    return 0;
}
