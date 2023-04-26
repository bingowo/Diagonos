#include <stdio.h>
#include <stdlib.h>

struct ALPHA {
    char alpha;
    int index;
};
struct ALPHA al[201];

int cmp(const void *a, const void *b) {
    struct ALPHA *aa = (struct ALPHA *) a, *bb = (struct ALPHA *) b;
    if ((aa->alpha >= 'A' && aa->alpha <= 'Z') && (bb->alpha >= 'A' && bb->alpha <= 'Z')) {
        if ((int) aa->alpha > (int) bb->alpha)
            return 1;
    }
    return -1;
}

int main() {
    int T, j;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        for (j = 0; (al[j].alpha = getchar()) != EOF; j++) {
            al[j].alpha = getchar();
        }
        qsort(al, j, sizeof(al[0]), cmp);
        printf("case #%d:\n", i);
        for(int x=0;x<j;x++)
            printf("%d",al[x].alpha);
        printf("\n");
    }

    return 0;
}
