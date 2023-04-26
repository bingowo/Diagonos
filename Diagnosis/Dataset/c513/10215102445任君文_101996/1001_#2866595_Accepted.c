#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char S[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a, i, j, n[100], r[100], res[100] = { 0 };
    scanf("%d", &a);
    for (i = 0; i < a; i++)
    {
        scanf("%d %d", &n[i], &r[i]);
    }
    for (i = 0; i < a; i++)
    {
        j = 0;
        if (n[i] < 0)
        {
            printf("-");
            n[i] = -n[i];
        }
        while (n[i] != 0)
        {
            res[j] = n[i] % r[i];
            j++;
            n[i] = n[i] / r[i];
        }
        j = j - 1;
        while (j >= 0)
        {
            printf("%c", S[res[j]]);
            j--;
        }
        printf("\n");
    }

    return 0;
}