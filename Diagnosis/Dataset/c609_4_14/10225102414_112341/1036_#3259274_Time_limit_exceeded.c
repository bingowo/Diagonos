#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Cal(char *I, int i, int times)
{
    int j, mul = 1, n, k;
    if (I[i] == '('){
        for (j = 1;I[i + j] == '(';j++){
            mul *= 2;
            times += 1;
        }
        n = 1;
        for (k = 1;n != 0;k++){
            if (I[i + k] == '('){
                n += 1;
            }else if (I[i + k] == ')'){
                n -= 1;
            }
        }
        return mul * Cal(I, i + j, times) + Cal(I, i + k, 0);
    }else if (I[i] == ')'){
        if (times > 0){
            return Cal(I, i + 1, times - 1);
        }else{
            return 1;
        }
    }
    return 0;
}

int main()
{
    char I[51];
    int point;
    while (1){
        scanf("%s", I);
        point = Cal(I, 0, 0);
        printf("%d\n", point);
    }
    return 0;
}
