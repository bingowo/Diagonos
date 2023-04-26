#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t u32;
typedef int32_t i32;

typedef struct {
    char str[21];
    i32 digit_cnt;
} Rec;

int cmp(void const *restrict lhs, void const *restrict rhs) {
    return ((Rec *)lhs)->digit_cnt == ((Rec *)rhs)->digit_cnt
               ? strcmp(((Rec *)lhs)->str, ((Rec *)rhs)->str)
               : ((Rec *)rhs)->digit_cnt - ((Rec *)lhs)->digit_cnt;
}

int main() {
    u32 t; scanf("%u", &t);
    for (u32 i = 0; i < t; ++i) {
        printf("case #%u:\n", i);
        u32 n; scanf("%u", &n);
        Rec recs[100];
        for (u32 i = 0; i < n; ++i) {
            scanf("%s", recs[i].str);
            recs[i].digit_cnt = 0;
            // 26 letters take one bit indivisually.
            u32 bit_cnt = 0;
            for (char *j = recs[i].str; *j; ++j) {
                u32 bit = 1 << (*j - 'A');
                if ((bit_cnt & bit) == 0)
                    bit_cnt |= bit,
                    ++recs[i].digit_cnt;
            }
        }
        qsort(recs, n, sizeof(Rec), cmp);
        for (u32 i = 0; i < n; ++i)
            puts(recs[i].str);
    }
}