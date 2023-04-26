#include <stdio.h>
#include <string.h>

void output(char (*O)[100], int num, int M)
{
    int len = 0, aver, rest, Space[70] = {0}, i, j;
    for (i = 0;i < num;i++){
        len += strlen(O[i]);
    }
    aver = (M - len) / (num - 1);rest = M - len - aver * (num - 1);
    for (i = 0;i < num - 1;i++) Space[i] = aver;
    for (j = i - 1;j >= num - 1 - rest;j--) Space[j] += 1;
    for (i = 0;i < num;i++){
        printf("%s", O[i]);
        for (j = 0;j < Space[i];j++) printf(" ");
    }
}

int main()
{
    int T, i;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        int M, len = 0, num = 0, j, o = 0;
        char O[100][100], ch;
        scanf("%d", &M);getchar();ch = getchar();
        printf("case #%d:\n", i);
        while (ch != '\n'){
            if (ch != ' '){
                for (j = 0;ch != ' ' && ch != '\n';ch = getchar()) O[o][j++] = ch;
                if (ch == '\n') ungetc(ch, stdin);
                O[o][j] = '\0';
                len += strlen(O[o]);
                num += 1;
                if (len > M + 1 - num){
                    output(O, num - 1, M);printf("\n");
                    strcpy(O[0], O[o]);
                    o = 0;
                    num = 1;len = strlen(O[o]);
                }
                o += 1;
            }
            ch = getchar();
        }
        for (j = 0;j < num;j++) printf("%s ", O[j]);
        printf("\n");
    }
    return 0;
}