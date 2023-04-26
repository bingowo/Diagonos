#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int strnumcmp(const void *a, const void *b)
{
    char *A = *(char **)a, *B = *(char **)b, C[8];
    unsigned char c1, c2;
    int i, j, n = 0, x = 0, y = 0;
    memset(C, '\0', 8);
    for (i = 0;i < strlen(A);i++){
        if (A[i] > 47 && A[i] < 58){
            for (j = 0;A[i] > 47 && A[i] < 58;i++){
                C[j] = A[i];
                j++;
            }
            x = atoi(C);
            memset(C, '\0', 8);
            n += 1;
            break;
        }
    }
    for (i = 0;i < strlen(B);i++){
        if (B[i] > 47 && B[i] < 58){
            for (j = 0;B[i] > 47 && B[i] < 58;i++){
                C[j] = B[i];
                j++;
            }
            y = atoi(C);
            memset(C, '\0', 8);
            break;
        }else if(i == strlen(B) - 1 && n == 0){
            return strcmp(A, B);
        }
    }
    j = 0;
    do {
        c1 = A[j];
        c2 = B[j++];
        if (c1 == '\0' && ((c2 > 47 && c2 < 58))){
            if (A[j - 2] > 47 && A[j - 2] < 58){
                c1 = A[j - 2];
                c2 = B[j - 2];
                break;
            }else{
                return -1;
            }
        }else if (c2 == '\0' && (c1 > 47 && c1 < 58)){
            if (B[j - 2] > 47 && B[j - 2] < 58){
                c1 = A[j - 2];
                c2 = B[j - 2];
                break;
            }else{
                return -1;
            }
        }
    } while(c1 == c2);

    if ((c1 > 47 && c1 < 58) && (c2 < 47 || c2 > 58)){
        return 1;
    }else if((c2 > 47 && c2 < 58) && (c1 < 47 || c1 > 58)){
        return -1;
    }else{
        return x - y;
    }
}

int main()
{
    char **I;
    int i, j;
    I = (char **)malloc(sizeof(char *) * 100);
    for (i = 0;i < 100;i++){
        I[i] = (char *)malloc(sizeof(char) * 30);
    }
    for (i = 0;scanf("%s", I[i]) != EOF;i++);
    qsort(I, i, sizeof(char *), strnumcmp);
    for (j = 0;j < i;j++){
        printf("%s ", I[j]);
    }
    return 0;
}
