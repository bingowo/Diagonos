#include <stdio.h>
#include <stdlib.h>

struct dic {
    long long date;
    long long bit;
} dic;

int cmp(const void *a, const void *b) {
    struct dic *aa = (struct dic *) a;
    struct dic *bb = (struct dic *) b;
    if ((aa->bit) != (bb->bit)) {
        return (bb->bit) - (aa->bit);
    } else if ((aa->bit) == (bb->bit)) {
        if ((aa->date) > (bb->date)) {
            return 1;
        } else return -1;
    }
}

int main() {


    int T;
    long long temp;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);
        struct dic s[N];

        for (int v = 0; v < N; v++) {
            scanf("%lld", &s[v].date);
            s[v].bit = 0;
        }

        for (int j = 0; j < N; j++) {
            temp = s[j].date;
            while (temp) {
                temp = temp & (temp - 1);
                s[j].bit++;
            }
        }

        qsort(s, N, sizeof(s[0]), cmp);
        printf("case #");
        printf("%d:\n", i);
        for (int x = 0; x < N; x++) {
            printf("%lld ", s[x].date);
        }
        printf("\n");
    }
    return 0;
}