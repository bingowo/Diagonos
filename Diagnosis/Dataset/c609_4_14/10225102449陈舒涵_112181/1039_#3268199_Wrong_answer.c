#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    char s1[81], s2[81], s[81];
    for (int t = 0; t < T; t ++){
        scanf("%s %s %s", s1, s2, s);
        int i = 0, j = 0, min = -1, max = -1;
        printf("case #%d:\n", t);
        while (i < strlen(s)){
            j = 0;
            while (j < strlen(s1) && s[i + j] == s1[j]){
                j ++;
            }
            if (j == strlen(s1)) break;
            i ++;
        }
        if (i == strlen(s)){
            printf("0\n");
        }
        else {
            i += strlen(s1);
            min = i;
            while (i < strlen(s)){
                j = 0;
                while (j < strlen(s2) && i + j < strlen(s) && s[i + j] == s2[j]){
                    j ++;
                }
                if (j == strlen(s2)) max = i;
                i ++;
            }
            if (max == -1){
                printf("0\n");
            }
            else{
                printf("%d\n", max - min);
            }
        }
    }
    return 0;
}