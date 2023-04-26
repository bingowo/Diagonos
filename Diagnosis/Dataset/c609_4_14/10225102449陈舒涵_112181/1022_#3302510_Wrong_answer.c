#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char m[10000];
    char n[10000];
} EMAIL;

int cmp(const void *a1, const void *b1)
{
    EMAIL a = *(EMAIL*)a1;
    EMAIL b = *(EMAIL*)b1;
    if (strcmp(a.n, b.n) != 0){
        return strcmp(a.n, b.n);
    }
    else{
        return -1 * strcmp(a.m, b.m);
    }
}

int main()
{
    int n, j;
    scanf("%d", &n);
    char c = getchar();
    EMAIL *a = (EMAIL*)malloc(sizeof(EMAIL) * 1000000);
    for (int i = 0; i < n; i ++){
        j = 0;
        while ((c = getchar()) != '@'){
            a[i].m[j++] = c;
        }
        a[i].m[j] = '\0';
        j = 0;
        while ((c = getchar()) != '\n' && c != EOF){
            a[i].n[j++] = c;
        }
        a[i].n[j] = '\0';
    }
    qsort(a, n, sizeof(EMAIL), cmp);
    for (int i = 0; i < n; i ++){
        printf("%s@%s\n", a[i].m, a[i].n);
    }
    free(a);
    return 0;
}