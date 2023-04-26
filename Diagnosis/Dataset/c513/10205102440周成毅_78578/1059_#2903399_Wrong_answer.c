#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n) {
    if (m % n == 0)return n;
    else return gcd(n, m % n);
}

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, s, temp;
    int *p;
    scanf("%d %d", &n, &s);
    p = (int *) malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        p[i] = temp;
    }
    p[n] = 1001;
    qsort(p, n + 1, sizeof(int), cmp);
    int j = 0;
    int length = 1;
    int height = 0;
    int sum = 0;
    for (; j < n + 1; j++) {
        if (p[j] == p[j + 1]) length++;
        else if (p[j] != p[j + 1] && j + 1 != n + 1) {
            height = p[j + 1] - p[j];
            if ((sum + height * length) > s) {
                if ((s - sum) % length == 0) {
                    printf("%d\n", p[j] + (s - sum) / length);
                    break;
                } else if ((s - sum) % length != 0) {
                    if ((p[j] + ((s - sum) / length)) != 0) {
                        printf("%d+%d/%d\n", (s - sum) / length, ((s - sum) % length) / gcd(s - sum, length),
                               length / gcd(s - sum, length));
                        break;
                    } else {
                        printf("%d/%d\n", ((s - sum) % length) / gcd(s - sum, length), length / gcd(s - sum, length));
                        break;
                    }
                }
            } else if ((sum + height * length) == s) {
                printf("%d\n", p[j + 1]);
                break;
            } else {
                sum = sum + height * length;
                length++;
                height = 0;
            }
        } else if (j + 1 == n + 1) {
            printf("%d+%d/%d\n", p[j] + ((s - sum) / (length - 1)),
                   ((s - sum) % (length - 1)) / gcd(s - sum, length - 1), (length - 1) / gcd(s - sum, length - 1));
            break;
        }
    }
    free(p);
    return 0;
}
