#include <stdio.h>

int max(int x, int y) { return x > y ? x : y; }

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        int b[31], sz = 0;
        do {
            b[sz++] = n & 1;
        } while (n >>= 1);
        int ans = 1;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (b[j] != b[j - 1]) {
                    ans = max(j - i + 1, ans);
                } 
                else { break;}
            }
        }
        printf("case #%d:\n%d\n", i, ans);
    }
}