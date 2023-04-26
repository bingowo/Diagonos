#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generate_combinations(const char *s, char *buffer, int index, int start);

int compare(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        char s[17];
        scanf("%s", s);

        int len = strlen(s);
        qsort(s, len, sizeof(char), compare);

        // Remove duplicates
        int new_len = 0;
        for (int j = 0; j < len; j++) {
            if (j == 0 || s[j] != s[j - 1]) {
                s[new_len++] = s[j];
            }
        }
        s[new_len] = '\0';

        printf("case #%d:\n", i);

        char buffer[17];
        generate_combinations(s, buffer, 0, 0);
    }

    return 0;
}

void generate_combinations(const char *s, char *buffer, int index, int start) {
    if (s[start] == '\0') {
        return;
    }

    for (int i = start; s[i] != '\0'; i++) {
        buffer[index] = s[i];
        buffer[index + 1] = '\0';
        printf("%s\n", buffer);
        generate_combinations(s, buffer, index + 1, i + 1);
    }
}
