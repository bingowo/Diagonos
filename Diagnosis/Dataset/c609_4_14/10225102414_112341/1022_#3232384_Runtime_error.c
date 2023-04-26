#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char user[1000000], host[1000000];
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
    int T, i, j, k;
    char *I = (char *)malloc(1000000), *C = (char *)malloc(1000000);
    scanf("%d", &T);
    mes *M = (mes *)malloc(sizeof(mes) * T);
    for (i = 0;i < T;i++){
        memset(C, '\0', 1000);
        scanf("%s", I);
        for (j = 0;I[j] != '@';j++);
        I[j++] = '\0';
        for (k = 0;I[j] != '\0';j++){
            C[k] = I[j];
            k += 1;
        }
        strcpy(M[i].user, I);strcpy(M[i].host, C);
    }
    qsort(M, T, sizeof(mes), cmp);
    for (i = 0;i < T;i++){
        printf("%s@%s\n", M[i].user, M[i].host);
    }
    return 0;
}