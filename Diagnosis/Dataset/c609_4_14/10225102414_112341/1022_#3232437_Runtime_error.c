#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *user, *host;
}mes;

int cmp(const void *a, const void *b)
{
    mes *A = (mes *)a, *B = (mes *)b;
    if (strcmp(A->host, B->host) == 0){
        return strcmp(B->user, A->user);
    }else{
        return strcmp(A->host, B->host);
    }
}

int main()
{
    int T, N, i, j, k;
    scanf("%d", &T);
    N = 10000000 / T;
    mes *M = (mes *)malloc(sizeof(mes) * T);
    for (i = 0;i < T;i++){
        M[i].host = (char *)malloc(sizeof(char) * N);
        M[i].user = (char *)malloc(sizeof(char) * N);
    }
    char *I = (char *)malloc(N), *C = (char *)malloc(N);
    for (i = 0;i < T;i++){
        memset(C, '\0', 1000);
        scanf("%s", I);
        for (j = 0;I[j] != '@';j++);
        I[j++] = '\0';
        for (k = 0;I[j] != '\0';j++){
            C[k] = I[j];
            k += 1;
        }
        C[k] = '\0';
        strcpy(M[i].user, I);strcpy(M[i].host, C);
    }
    qsort(M, T, sizeof(mes), cmp);
    for (i = 0;i < T;i++){
        printf("%s@%s\n", M[i].user, M[i].host);
    }
    return 0;
}