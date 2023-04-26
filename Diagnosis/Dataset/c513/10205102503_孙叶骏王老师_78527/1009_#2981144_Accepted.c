#include <stdio.h>

int popcount[256];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {
    char s[125];
    scanf("%*[\n]%[^\n]%", s);
    int numerator = 0, denominator = 0;
    for (int i = 0; s[i]; i++) {
        numerator += 8, denominator += popcount[(unsigned char)s[i]];
    }
    int g = gcd(numerator, denominator);
    numerator /= g, denominator /= g;
    printf("%d/%d\n", denominator, numerator);
}

int main() {
    popcount[0] = 0;
    for (int i = 1; i < 256; i++) {
        popcount[i] = popcount[i >> 1] + (i & 1);
    }

    int t;
    scanf("%d%", &t);
    while (t--) {
        solve();
    }
}