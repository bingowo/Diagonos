#include <stdio.h>
#include <string.h>

#define MAX_LEN 505

int main() {
    char a[MAX_LEN], b[MAX_LEN];
    int n;
    scanf("%s %s %d", a, b, &n);
    int lena = strlen(a), lenb = strlen(b);
    int len = lena > lenb ? lena : lenb;
    int dot_pos = -1;
    for (int i = 0; i < len; i++) {
        if (a[i] == '.') {
            dot_pos = i;
            break;
        }
        if (a[i] == '\0') {
            dot_pos = i;
            a[i] = '.';
            a[i + 1] = '\0';
            break;
        }
    }
    if (dot_pos == -1) {
        dot_pos = len;
        a[len] = '.';
        a[len + 1] = '\0';
    }
    for (int i = 0; i < len; i++) {
        if (b[i] == '.') {
            break;
        }
        if (b[i] == '\0') {
            b[i] = '.';
            b[i + 1] = '\0';
            break;
        }
    }
    int dot_pos_b = strlen(b) - 1;
    while (b[dot_pos_b] == '0') {
        dot_pos_b--;
    }
    if (b[dot_pos_b] == '.') {
        b[dot_pos_b] = '\0';
    } else {
        b[dot_pos_b + 1] = '\0';
    }
    int dot_pos_a = strlen(a) - 1;
    while (a[dot_pos_a] == '0') {
        dot_pos_a--;
    }
    if (a[dot_pos_a] == '.') {
        a[dot_pos_a] = '\0';
    } else {
        a[dot_pos_a + 1] = '\0';
    }
    int dot_pos_res = dot_pos > dot_pos_b ? dot_pos : dot_pos_b;
    printf("%s\n", a);
    printf("%s\n", b);
    printf("%d\n", dot_pos_res);
    int carry = 0;
    char res[MAX_LEN];
    int pos = 0;
    for (int i = dot_pos_res + 1; i < MAX_LEN; i++) {
        int numa = 0, numb = 0;
        if (i - dot_pos - 1 >= 0 && i - dot_pos - 1 < lena) {
            numa = a[dot_pos_a - (i - dot_pos - 1)] - '0';
        }
        if (i - dot_pos_b - 1 >= 0 && i - dot_pos_b - 1 < lenb) {
            numb = b[dot_pos_b - (i - dot_pos_b - 1)] - '0';
        }
        int sum = numa + numb + carry;
        carry = sum / 10;
        res[pos++] = sum % 10 + '0';
        if (i == dot_pos_res + n) {
            break;
        }
    }
    if (carry > 0) {
        res[pos++] = carry + '0';
    }
    if (pos == 0) {
        printf("0\n");
        return 0;
    }
    printf("%c", res[pos - 1]);
    if (n > 0) {
        printf(".");
    }
    for (int i = pos - 2, j = 0; j < n; j++, i--) {
        if (i < 0) {
            printf("0");
        } else {
            printf("%c", res[i]);
        }
    }
    printf("\n");
    return 0;
}
