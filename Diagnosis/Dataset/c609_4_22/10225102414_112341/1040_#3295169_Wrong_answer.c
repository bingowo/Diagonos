#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int judge(char *I, int i)
{
    int times;
    if (isdigit(I[i])){
        times = atoi(I + i);
    }else if (I[i] != '-'){
        if (I[i + 1] == 'x') times = 1;
        else times = atoi(I + i + 1);
    }else{
        if (I[i + 1] == 'x') times = -1;
        else times = -atoi(I + i + 1);
    }
    return times;
}

void cal(int *L, char *I)
{
    int i, l = strlen(I), times = 1;
    for (i = 0;i < l;i++){
        if (isdigit(I[i]) && times != 0 && i != 0) continue;
        else if (I[i] == 'x'){
            if (I[i + 1] != '^'){
                L[1] = times;times = 0;
            }else{
                i += 2;
                L[I[i] - '0'] = times;times = 0;
            }
        }else times = judge(I, i);
    }
    if (times != 0) L[0] = times;
}

int main()
{
    char I[102];
    while (scanf("%s", I) != EOF){
        int L1[50] = {0}, L2[50] = {0}, O[50] = {0}, i, j;
        cal(L1, I);scanf("%s", I);cal(L2, I);
        for (i = 0;i < 50;i++)
            for (j = 0;j < 50;j++){
                O[i + j] += L1[i] * L2[j];
            }
        for (i = 49;i >= 0;i--){
            if (O[i] != 0) printf("%d ", O[i]);
        }
        printf("\n");
    }
    return 0;
}
