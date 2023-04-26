#include <stdio.h>
#include <string.h>

char *Morse[] = {".-", "-...", "-.-.", "-..", ".",
    "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---",
    ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----."
    };

void Solve(char *s) {
    char ans[500];
    char code[6];
    int cnt = 0;
    int i = 0;
    while (s[i]) {
        int j = 0;
        while (s[i] == '.' || s[i] == '-')
            code[j++] = s[i++];
        code[j] = '\0';
        for (int k = 0; k < 36; ++k)
            if (strcmp(code, Morse[k]) == 0) {
                if (k < 26)
                    ans[cnt++] = k + 'A';
                else
                    ans[cnt++] = k + '0' - 26;
                break;
            }
        
        int flag = 0;
        while (s[i] == '/')
            ++flag, ++i;
        if (flag == 3)
            ans[cnt++] = ' ';
        else if (flag == 5)
            ans[cnt++] = '.';
    }
    ans[cnt] = '\0';    

    //output
    printf("%s\n", ans);
}

int main() {
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; ++t) {
        char s[1001];
        scanf("%s", s);
        printf("case #%d:\n", t);
        Solve(s);
    }
    return 0;
}