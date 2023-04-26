#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 1000
#define DIVISOR 2333

int main(void)
{
    int n, i;
    long long in;
    int temp;
    unsigned int j;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int res[MAX_DIGITS] = {0};
        int res_size = 0;

        scanf("%lld", &in);

        while (in >= DIVISOR) {
            temp = in % DIVISOR;
            in = in / DIVISOR;
            res[res_size++] = temp;
        }

        res[res_size++] = (int)in;

        for (j = res_size - 1; j > 0; j--) {
            printf("%d ", res[j]);
        }
        printf("%d\n", res[j]);
    }

    return 0;
}
