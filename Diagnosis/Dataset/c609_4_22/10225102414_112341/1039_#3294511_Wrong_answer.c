#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int B[100], S[100];
}list;

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    char s1[81], s2[81], ch;
    int T, i;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        int be1, be2, len = 0, x = 0, y = 0, l1, l2, j = 0, k = 0;
        list S1, S2;
        scanf("%s%s", s1, s2);getchar();
        l1 = strlen(s1);l2 = strlen(s2);
        for (ch = getchar();ch != '\n';len++){
            if (ch == s1[x] && x < l1){
                if (x == 0){

                    be1 = len;
                }
                if (x == l1 - 1){
                    S1.B[j] = be1;
                    S1.S[j++] = len;
                    x = 0;
                }
                x += 1;
            }else x = 0;
            if (ch == s2[y] && y < l2){
                if (y == 0){
                    be2 = len;
                }
                if (y == l2 - 1){
                    S2.B[k] = be2;
                    S2.S[k++] = len;
                    y = 0;
                }
                y += 1;
            }else y = 0;
            ch = getchar();
        }
        if (j != 1){
            qsort(S1.B, j, sizeof(int), cmp);qsort(S1.S, l1, sizeof(int), cmp);
        }
        if (k != 1){
            qsort(S2.B, k, sizeof(int), cmp);qsort(S2.S, l2, sizeof(int), cmp);
        }
        printf("case #%d:\n", i);
        if (k == 0 || j == 0){
            printf("0\n");
        }else{
            printf("%d\n", ((S2.B[k - 1] - S1.S[0] > S1.B[j - 1] - S2.S[0]) ? S2.B[k - 1] - S1.S[0] : S1.B[j - 1] - S2.S[0]) - 1);
        }
    }
    return 0;
}