#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int T, i, j, p;
    char I[53];
    double a;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        a = 0;
        scanf("%s", I);
        for (p = 0;I[p] != '.';p++);
        for (j = 1;j < strlen(I) - 1;j++){
            a += (I[j + p] - '0') * pow(0.125, j);
        }

        printf("case #%d:\n%.50g\n", i, a);
    }
    return 0;
}
