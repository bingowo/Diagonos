#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) {
    char *aa = (char *) a, *bb = (char *) b;
    if ((*aa >= 'A' && *aa <= 'Z') && (*bb >= 'A' && *bb <= 'Z')) {
        if ((int) *aa > (int) *bb)
            return 1;
    }
    return -1;
}

int main() {
    int T, j;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char al[201],c;
        for (j = 0; (c = getchar()) != EOF; j++) {
            al[j] = c;
        }
        qsort(al, j, sizeof(al[0]), cmp);
        printf("case #%d:\n", i);
        for(int x=0;x<j;x++)
            printf("%d",al[x]);
        printf("\n");
    }
    return 0;
}
