#include <stdio.h>
#include <string.h>


int main() {
    char s[100];
    scanf("%s", s);
    int ll = strlen(s);
    int i = 0;
    int temp = 0;
    int a = 0;
    int b = 0;
    while (i < ll) {
        if (s[i] > 57 || s[i] < 48) {
            i++;
            a = 0;
            temp = 0;
        } else if (s[i] == 48 && temp == 0) {
            i++;
            a = 0;
        } else if (s[i] > 48 && s[i] < 58) {
            a++;
            temp = 1;
            i++;
            if (a > b) b = a;
        } else if (s[i] == 48 && temp == 1) {
            i++;
            a++;
            temp = 1;
            if (a > b) b = a;
        }
    }
    printf("%d\n", b);
    return 0;
}