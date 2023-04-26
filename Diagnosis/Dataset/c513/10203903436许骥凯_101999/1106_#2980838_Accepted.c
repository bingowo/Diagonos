#include<stdio.h>
#include<string.h>
#define MOD 1000000007
#define ll long long
int main(){
    char s[1001]; scanf("%s", s);
    ll res = 1LL, len = strlen(s);
    if (len == 1){
        printf("1\n");
        return 0;
    }
    if (s[0] != s[1]) res++;
    for (int i = 1; i < len - 1; i++){
        int temp = 3;
        if (s[i] == s[i-1]) temp--;
        if (s[i] == s[i+1]) temp--;
        if (s[i-1] == s[i+1]) temp--;
        if (temp < 1) temp = 1; 
        res = (ll)res * temp % MOD;
    }
    if (s[len-1] != s[len-2]) res = res * 2LL % MOD;
    printf("%lld\n", res);
}