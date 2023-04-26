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

    for (int i = 0; i < 26; i++) {
        if (char_count[0][i] > 0) {
            bool possible = true;
            int min_changes_for_char = 1000000;
            for (int j = 0; j < n; j++) {
                if (char_count[j][i] == 0) {
                    possible = false;
                    break;
                }
                int min_changes_j = 0;
                for (int k = 0; k < n; k++) {
                    min_changes_j += abs(char_count[j][i] - char_count[k][i]);
                }
                if (min_changes_j < min_changes_for_char) {
                    min_changes_for_char = min_changes_j;
                }
            }
            if (!possible) {
                return -1;
            }
            result += min_changes_for_char;
        }
    }

    return result;
}
