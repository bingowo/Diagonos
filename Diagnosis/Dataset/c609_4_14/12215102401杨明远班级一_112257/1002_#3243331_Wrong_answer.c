#include <stdio.h>

int get_max_len(unsigned int n) {
    int max_len = 1;
    int cur_len = 1;
    unsigned int prev_bit = n & 1;

    while (n > 0) {
        n >>= 1;
        unsigned int cur_bit = n & 1;
        if (cur_bit != prev_bit) {
            cur_len++;
        } else {
            max_len = (cur_len > max_len) ? cur_len : max_len;
            cur_len = 1;
        }
        prev_bit = cur_bit;
    }

    max_len = (cur_len > max_len) ? cur_len : max_len;
    return max_len;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        unsigned int n;
        scanf("%u", &n);
        printf("case #%d:\n%d\n", i, get_max_len(n));
    }
    return 0;
}
