#include<stdio.h>
#include<string.h>

int main(){
    int table[128]; table['I'] = 1; table['V'] = 5; table['X'] = 10;
                    table['L'] = 50; table['C'] = 100; table['D'] = 500; table['M'] = 1000;
    char s[1000]; scanf("%s", s); int slen = strlen(s);
    long long res = 0; int fac = 1000;
    for (int i = slen - 1; i >= 0; i--){
        if (s[i] == ')') continue;
        if (s[i] == '('){res *= fac; continue;}
        res += table[s[i]];
        if (i == 0) break;
        if (table[s[i]] > table[s[i-1]])
            res -= table[s[--i]];
    }
    printf("%lld\n", res);
    return 0;
}