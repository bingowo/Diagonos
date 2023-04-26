#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

void solve(char *s) {
    int len = strlen(s);
    int cnt1 = 0;
    for (int i = 0; i < len; i++) {
        unsigned char c = s[i];
        for (int j = 0; j < 8; j++) {
            cnt1 += c % 2;
            c /= 2;
        }
    }
    int g = gcd(cnt1,len*8);
    //printf("%d\n",g);
    printf("%d/%d\n",cnt1/g,len*8/g);
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++) {
        char s[121];
        gets(s);
        solve(s);
    }

    return 0;
}
