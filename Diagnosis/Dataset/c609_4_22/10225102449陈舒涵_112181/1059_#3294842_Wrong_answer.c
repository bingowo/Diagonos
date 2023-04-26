#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char s[101];
    int t;  //t用于记录正负
    char z[101];
    char f[101];
} NUMBER;

int cmp(const void *a1, const void *b1)
{
    NUMBER a = *(NUMBER*)a1;
    NUMBER b = *(NUMBER*)b1;
    int k = 1;
    if (a.t < 0 && b.t < 0) k = -1;
    if (a.t != b.t){
        return a.t - b.t;
    }
    else if (strlen(a.z) != strlen(b.z)){
        return k * (strlen(a.z) - strlen(b.z));
    }
    else{
        int i = 0;
        while (i < strlen(a.z)){
            if (a.z[i] != b.z[i]) return k * (a.z[i] - b.z[i]);
            i ++;
        }
        int j = 0;
        while (j < strlen(a.f) && j < strlen(b.f)){
            if (a.f[i] != b.f[i]) return k * (a.f[i] - b.f[i]);
            j ++;
        }
        if (j == strlen(a.f)){
            return k * (-1);
        }
        else{
            return k;
        }
    }
}

int main()
{
    int n, j, p, q;
    scanf("%d", &n);
    NUMBER *a = (NUMBER*)malloc(sizeof(NUMBER) * n);
    for (int i = 0; i < n; i ++){
        scanf("%s", a[i].s);
        j = 0;
        a[i].t = 1;
        if (a[i].s[0] == '-'){
            a[i].t = -1;
            j ++;
        }
        else if (a[i].s[0] == '+'){
            j ++;
        }
        p = 0;
        while (j < strlen(a[i].s) && a[i].s[j] != '.'){
            a[i].z[p] = a[i].s[j];
            p ++;
            j ++;
        }
        a[i].z[p] = '\0';
        q = 0;
        while (j < strlen(a[i].s)){
            a[i].f[q] = a[i].s[j];
            q ++;
            j ++;
        }
        a[i].f[q] = '\0';
    }
    qsort(a, n, sizeof(NUMBER), cmp);
    for (int i = 0; i < n; i ++){
        printf("%s\n", a[i].s);
    }
    free(a);
    return 0;
}