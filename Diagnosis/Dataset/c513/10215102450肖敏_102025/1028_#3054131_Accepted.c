#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;//从小到大排序
}

int main() {
    char c;
    scanf("%c", &c);
    int a[100];
    int i = 0;
    while (scanf("%d", &a[i]) != EOF)
        i++;
    qsort(a, i, sizeof(a[0]), cmp);
    if (c == 'A')//升序
    {
        for (int j = 0; j < i; j++) {
            if (a[j] == a[j + 1])
                continue;
            else
                printf("%d ", a[j]);
        }
    } else {
        for (int j = i-1; j >=0; j--) {
            if (a[j] == a[j-1])
                continue;
            else
                printf("%d ", a[j]);
        }
    }
    return 0;
}
