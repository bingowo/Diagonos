#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    char *A = (char *)a, *B = (char *)b;
    return strcmp(A, B);
}

int main()
{
    char I[100][500], c;
    int T, i, j, k;
    scanf("%d", &T);getchar();
    for (i = 0;i < T;i++){
        c = getchar();
        for (j = 0;c != '\n';j++){
            k = 0;
            while (c >= 'a' && c <= 'z'){
                I[j][k++] = c;
                c = getchar();
            }
            while (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?'){
                c = getchar();
            }
            I[j][k] = '\0';
        }
        qsort(I, j, sizeof(char) * 100, cmp);
        printf("case #%d:\n", i);
        for (k = 0;k < j;k++){
            if (k > 0 && strcmp(I[k - 1], I[k]) == 0){
                continue;
            }else{
                printf("%s ", I[k]);
            }
        }
        printf("\n");
    }
    return 0;
}