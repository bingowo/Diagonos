#include<stdio.h>
#include<string.h>


long long gcd(long long a, long long b){
    return (b != 0? gcd(b, a % b): a);
}

int main(){
    char s[50]; scanf("%s", s);
    int table[128]; table['2'] = -1; table['0'] = 0; table['1'] = 1;
    long long IntPart = 0; int i = 0;
    for (; i < strlen(s) && s[i] != '.'; ++i)
        IntPart = IntPart * 3 + table[s[i]];
    if (i == strlen(s)) printf("%lld\n", IntPart);
    else{
        long long top = 0, bottom = 1;
        for (++i; i < strlen(s); ++i){
            top = top * 3 + table[s[i]];
            bottom *= 3;
        }
        if (IntPart > 0 && top < 0) --IntPart, top += bottom;
        else if (IntPart < 0 && top > 0) ++IntPart, top = bottom - top;
        if (IntPart) printf("%lld ", IntPart);
        int div = gcd(top, bottom);
        printf("%lld %lld\n", top / div, bottom / div);
    }
    return 0;
}