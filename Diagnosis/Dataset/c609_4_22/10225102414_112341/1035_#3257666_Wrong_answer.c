#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Count(char *p, char c)
{
    int i;
    for (i = 1;p[i] == c;i++);
    return i;
}

int Delete(char *I)
{
    int i, j, l, n, K = 0, res = 0;
    l = strlen(I);
    for (i = 0;i < l;i++){
        n = Count(I + i, I[i]);
        if (n > 1){
            res += n;
            K = 1;
            for (j = i;j < i + n;j++){
                I[j] = 'D';
            }
            i += n - 1;
        }
    }
    for (i = 0;i < l;i++){
        if (I[i] == 'D'){
            for (j = i + 1;I[j] == 'D' && j < l;j++);
            I[i] = I[j];
            I[j] = 'D';
        }
    }
    for (i = l - res;i <= 102;i++){
        I[i] = '\0';
    }
    if (K == 0){
        return 0;
    }
    return res + Delete(I);
}

int main()
{
    int T, l, i, j, k, large, res, N[102] = {0};
    char I[102], M[102];
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        memset(N, 0, 102 * sizeof(int));
        scanf("%s", I);
        res = Delete(I);
        l = strlen(I);
        for (j = 0;j < l;j++){
            strcpy(M, I);
            for (k = j;k < l;k++){
                M[k] = M[k + 1];
            }
            N[j] = Delete(M) + 2;
        }
        large = N[0];
        for (j = 1;j < l;j++){
            if (N[j] > large){
                large = N[j];
            }
        }
        if (l == 0){
            res += 1;
        }else{
            res += large;
        }
        printf("case #%d:\n%d\n", i, res);
    }
    return 0;
}
