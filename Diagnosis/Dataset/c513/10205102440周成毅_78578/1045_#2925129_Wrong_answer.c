#include <stdio.h>
#include <string.h>

#define MAXN 3000
#define MAXM 70

char s[MAXN];

char words[MAXN][MAXM];

int main() {
    int pnum;
    scanf("%d\n", &pnum);
    for (int i = 0; i < pnum; i++) {
        int m;
        scanf("%d\n", &m);
        char c = 0;
        int l = 0;
        while ((s[l++] = c = getchar()) != '\n');
        s[--l] = '\0';
        int ws = 0;
        int k = 0;
        while (s[k] != '\0' && s[k] == ' ')
            k++;
        strcpy(s, s + k);
        k = 0;
        while (s[k] != '\0') {
            if (s[k] != ' ')
                ws = 0;
            else
                ws++;
            if (ws > 1) {
                while (s[k] == ' ') {
                    k++;
                    ws++;
                }
                k--;
                strcpy(s + k - ws + 2, s + k);
                ws = 0;
            }
            k++;
        }
        /*while (s[k] != '\0')
        {
            if (s[k] == ' '&& s[k+1] == ' ')
            {
                strcpy(s+k, s+k+1);
                continue;
            }
            k++;
        }*/
        l = strlen(s);
        s[l - 1] = '\0';
        printf("%s\n", s);
        printf("case #%d:\n", i);
        ws = 0;
        int i1 = 0;
        int ws1, zf, spnum;
        for (int i = 0; i < l; i++) {
            if (s[i] == ' ')
                ws++;
            if (i - i1 == m - 1) {
                if (s[i + 1] == ' ' || s[i + 1] == '\0') {
                    ws++;
                    i++;
                }
                ws1 = zf = 0;
                int j = 0;
                for (; j < m; j++) {
                    if (s[i1 + j] != ' ')
                        zf++;
                    else
                        ws1++;
                    if (ws1 == ws)
                        break;
                }
                ws1 = m - zf;
                /*printf("%d\n", ws1);*/
                int i2 = i1;
                int zf2 = 0;
                for (; zf2 < zf; i1++)
                    if (s[i1] != ' ')
                        zf2++;
                i1++;
                while (ws > 1) {
                    for (; s[i2] != ' '; i2++)
                        printf("%c", s[i2]);
                    i2++;
                    spnum = ws1 / (ws - 1);
                    for (int i = 0; i < spnum; i++)
                        printf(" ");
                    ws1 -= spnum;
                    ws--;
                }
                for (; s[i2] != ' ' && s[i2] != '\0'; i2++)
                    printf("%c", s[i2]);
                printf("\n");
                ws = 0;
                i = i1;
            }
        }
        if (i1 < l) {
            printf("%s\n", s + i1);
        }
    }
    return 0;
}