#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char s[20];
    char op[4];
    int num[4] = {0};
    char re;
    while(gets(s) != 0) {
        int i = 0;
        while(s[i] != ' ') {
            op[i] = s[i];
            i++;
        }
        op[i] = '\0';
        i++;
        re = s[i++];

        if (strcmp("OUT", op) == 0) {
            printf("%d\n", num[re - 'A']);
        } else {
            i += 2;
            if (strcmp(op, "IN") == 0) {
                int tmp;
                char tmpNum[12];
                int j = 0;
                while(s[i])
                    tmpNum[j++] = s[i++];
                tmpNum[j] = '\0';
                tmp = atoi(tmpNum);
                num[re-'A'] = tmp;
                // printf("num is changed!\nnum = %d\n", num[re-'A']);
                // printf("re = %c\n", re);
            } else {
                char other = s[i];
                // printf("Other = %c\n", other);
                if (strcmp(op, "MOV") == 0) {
                    // printf("Here, mov\n");
                    num[re-'A'] = num[other-'A'];
                    printf("a: %d = b: %d\n", num[re-'A'], num[other-'A']);
                } else if (strcmp(op, "ADD") == 0) {
                    num[re-'A'] = num[other-'A'] + num[re - 'A'];
                } else if (strcmp(op, "SUB") == 0) {
                    num[re-'A'] = num[re-'A'] - num[other - 'A'];
                } else if (strcmp(op, "MUL") == 0) {
                    num[re-'A'] = num[other-'A'] * num[re - 'A'];
                } else if (strcmp(op, "DIV") == 0) {
                    num[re-'A'] = num[re-'A'] / num[other - 'A'];
                }
            }
        }
        // for (int i = 0; i < 4; ++i)
        //     printf("%c: %d\n", i+'A', num[i]);
    }
    return 0;
}