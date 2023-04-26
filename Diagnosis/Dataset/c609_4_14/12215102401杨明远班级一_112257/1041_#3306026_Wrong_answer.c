#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_combinations(char *str, int start, int end, char *result, int index) {
    if (index > 0) {
        printf("%s, ", result);
    }

    for (int i = start; i < end; i++) {
        result[index] = str[i];
        result[index + 1] = '\0';
        generate_combinations(str, i + 1, end, result, index + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int t = 0; t < n; t++) {
        char input[17];
        scanf("%s", input);

        // 去重和排序
        char unique_chars[17] = "";
        int unique_index = 0;
        int len = strlen(input);
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < len; i++) {
                if (input[i] == c) {
                    unique_chars[unique_index++] = c;
                    break;
                }
            }
        }

        printf("case #%d: ", t);
        char result[17] = "";
        generate_combinations(unique_chars, 0, strlen(unique_chars), result, 0);
        printf("\n");
    }

    return 0;
}
