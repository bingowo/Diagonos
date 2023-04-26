#include <stdio.h>

#define MAXN 100
#define MAXV 1000

int a[MAXN + 1], n;

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int a[], int n, int direction) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if ((direction == 1 && a[j] > a[j + 1]) || (direction == -1 && a[j] < a[j + 1]))
                swap(&a[j], &a[j + 1]);
}

void uniq(int a[], int* n) {
    int i, j;
    for (i = 0; i < *n; i++) {
        for (j = i + 1; j < *n;) {
            if (a[j] == a[i]) {
                (*n)--;
                a[j] = a[*n];
            } else {
                j++;
            }
        }
    }
}

int main() {
    int i, direction;
    char c;
    scanf("%c", &c);
    if (c == 'A') {
        direction = 1;
    } else {
        direction = -1;
    }
    n = 0;
    while (scanf("%d", &a[n]) == 1) {
        n++;
    }
    uniq(a, &n);
    bubblesort(a, n, direction);
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
