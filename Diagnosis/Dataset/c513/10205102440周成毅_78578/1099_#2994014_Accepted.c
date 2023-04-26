#include <stdio.h>
#include <string.h>

#define MAXN 1010
#define MAXC 6

char c[36][MAXC] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-",
                    "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                    ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

void trans(char *d, char *s) {
    char sc[MAXC];
    int id = 0;
    int k = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        sc[k++] = s[i];
        //printf("%c", s[i]);
        if (s[i] == '/' || i == len - 1) {
            //printf("\n");
            if (i == len - 1)
                sc[k] = '\0';
            else
                sc[k - 1] = '\0';
            for (int i = 0; i < 36; i++)
                if (strcmp(sc, c[i]) == 0) {
                    if (i <= 9)
                        d[id++] = i + '0';
                    else
                        d[id++] = i - 10 + 'A';
                }
            if (i < len - 3 && s[i + 3] == '/' && s[i + 1] == '/' && s[i + 2] == '/') {
                d[id++] = '.';
                i += 4;
            } else if (i < len - 1 && s[i + 1] == '/') {
                d[id++] = ' ';
                i += 2;
            }
            k = 0;
            //printf("%c\n", d[id-1]);
        }
    }
    d[id] = '\0';
    //printf("%s\n", d);
}

char s[MAXN];
char chu[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        memset(chu, 0, sizeof(chu));
        scanf("%s", s);
        //printf("%s\n", s);
        trans(chu, s);
        printf("case #%d:\n%s\n", i, chu);
    }
    return 0;
}