#include <stdio.h>
#include <string.h>

double cal(int n)
{
    int i;
    double R = 0.125, re = 1;
    for (i = 0;i < n;i++){
        re *= R;
    }
    return re;
}

int main()
{
    int T, i, j, p;
    char I[53];
    double a ;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        a = 0;
        scanf("%s", I);
        for (p = 0;I[p] != '.';p++);
        for (j = 1;j < strlen(I) - 1;j++){
            a += (I[j + p] - '0') * cal(j);
        }
        printf("case #%d:\n%.100lf\n", i, a);
    }
    return 0;
}