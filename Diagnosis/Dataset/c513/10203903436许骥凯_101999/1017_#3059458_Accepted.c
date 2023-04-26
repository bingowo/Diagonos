#include <stdio.h>
#include <string.h>

int main() {
    int table[128];
    table['I'] = 1, table['V'] = 5, table['X'] = 10, table['L'] = 50,
    table['C'] = 100, table['D'] = 500, table['M'] = 1000;
    char s[50];
    scanf("%s", s);
    long long res[50], mult = 1;
    int rlen = 0;
    for (int i = 0; i != strlen(s); ++i) {
        if (s[i] == '(')
            mult *= 1000;
        else if (s[i] == ')')
            mult /= 1000;
        else
            res[rlen++] = table[s[i]] * mult;
    }
    long long resLL = 0;
    for (int i = 0; i != rlen - 1; ++i) {
        if (res[i] < res[i + 1])
            resLL -= res[i];
        else
            resLL += res[i];
    }
    resLL += res[rlen - 1];
    printf("%lld\n", resLL);
}