#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int judge(char *I, int i)
{
    int times;
    if (I[i] != '-'){
        if (I[i + 1] == 'x') times = 1;
        else times = atoi(I + i + 1);
    }else{
        if (I[i + 1] == 'x') times = -1;
        else times = -atoi(I + i + 1);
    }
    return times;
}
int main()
{
    char I[102];
    while (scanf("%s", I) != EOF){
        int L[50], i = 0, l = strlen(I), times = 1;
        for (i = 0;i < l;i++){
            if (I[i] == ' ') break;
            else if (I[i] == 'x'){
                if (I[i + 1] != '^') L[1] = times;
                else L[I[i + 2]] = times;
            }
            times = judge(I, i);

        }
    }
}