#include <stdio.h>
#include <string.h>

int cal(int n)
{
    int i, re = 1, R = 3;
    for (i = 0;i < n - 1;i++){
        re *= R;
    }
    return re;
}

int main()
{
    int T, i, j, k, a;
    char in[100];
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        a = 0;
        scanf("%s", in);
        for (k = 0;k < strlen(in);k++){
            if (in[k] == '-'){
                in[k] = 47;
            }
        }
        for (j = strlen(in) - 1;j >= 0;j--){
            a += (in[j] - 48) * cal(strlen(in) - j);
        }
        printf("case #%d:\n%d\n", i, a);
    }
}