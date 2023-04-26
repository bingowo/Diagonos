#include <stdio.h>

int Cal(char *I, int i)
{
    int j, n;
    if (I[i] == '\0' || I[i] == ')'){
        return 0;
    }else if (I[i + 1] == ')'){
        return 1 + Cal(I, i + 2);
    }else{
        n = 1;
        for (j = 1;n != 0;j++){
            if (I[i + j] == '('){
                n += 1;
            }else if (I[i + j] == ')'){
                n -= 1;
            }
        }
        return 2 * Cal(I, i + 1) + Cal(I, i + j);
    }
}

int main()
{
    char I[51];
    int point;
    scanf("%s", I);
    point = Cal(I, 0);
    printf("%d\n", point);
    return 0;
}

