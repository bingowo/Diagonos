#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100005
#define MAX_LEN 105

int min_changes(int n, int char_count[][26]);

int main() {
    int n;
    scanf("%d", &n);

    char strings[MAX_N][MAX_LEN];
    int char_count[MAX_N][26] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
        for (int j = 0; strings[i][j] != '\0'; j++) {
            char_count[i][strings[i][j] - 'a']++;
        }
    }

    int result = min_changes(n, char_count);
    printf("%d\n", result);

    return 0;
}

int min_changes(int n, int char_count[][26]) {
    int result = 0;
    int total_count[26] = {0};

    // Calculate total count for each character
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            total_count[i] += char_count[j][i];
        }
    }

    for (int i = 0; i < 26; i++) {
        if (total_count[i] % n != 0) {
            return -1;
        }
        result += total_count[i] / n - 1;
    }

    return result;
}
