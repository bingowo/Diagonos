#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 typedef struct
 {
     char NAME[64], TIME1[11], TIME2[6], SIZE[17];
 } LIST;

int cmpN(const void* a, const void *b)
{
    LIST *A = (LIST *)a, *B = (LIST *)b;
    return strcmp(A->NAME, B->NAME);
}

int cmpS(const void* a, const void *b)
{
    LIST *A = (LIST *)a, *B = (LIST *)b;
    int x, y, i, j = 0;
    char X[17], Y[17];
    for (i = 0;i < 17;i++){
        if (A->SIZE[i] != ' '){
            X[j++] = A->SIZE[i];
        }
    }
    j = 0;
    for (i = 0;i < 17;i++){
        if (B->SIZE[i] != ' '){
            Y[j++] = B->SIZE[i];
        }
    }
    x = atoi(X);y = atoi(Y);
    if (a == b){
        return strcmp(A->NAME, B->NAME);
    }else{
        return x - y;
    }
}

int cmpT(const void* a, const void *b)
{
    LIST *A = (LIST *)a, *B = (LIST *)b;
    if (strcmp(A->TIME1, B->TIME1) != 0){
        return strcmp(A->TIME1, B->TIME1);
    }else if (strcmp(A->TIME2, B->TIME2) != 0){
        return strcmp(A->TIME2, B->TIME2);
    }else{
        return strcmp(A->NAME, B->NAME);
    }
}
 int main()
 {
     int n, i, j;
     char W[11];
     while (scanf("%d", &n) != 0){
        LIST L[100];
        for (i = 0;i < n;i++){
            scanf("%s%s", L[i].TIME1, L[i].TIME2);
            getchar();
            for (j = 0;j < 16;j++){
                L[i].SIZE[j] = getchar();
            }
            L[i].SIZE[16] = '\0';
            getchar();
            scanf("%s", L[i].NAME);
        }
        scanf("%s", W);scanf("%s", W);
        if (W[1] == 'N'){
            qsort(L, n, sizeof(LIST), cmpN);
        }else if (W[1] == 'S'){
            qsort(L, n, sizeof(LIST), cmpS);
        }else{
            qsort(L, n, sizeof(LIST), cmpT);
        }
        for (i = 0;i < n;i++){
            printf("%s %s%s %s\n", L[i].TIME1, L[i].TIME2, L[i].SIZE, L[i].NAME);
        }
        printf("\n");
     }
     return 0;
 }