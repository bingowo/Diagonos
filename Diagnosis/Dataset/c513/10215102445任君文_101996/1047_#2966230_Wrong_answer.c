#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define M 500
int main()
{
    int T;
    int i, j, n, temp;
    char c;
    int s[M] = { 0 };
    int L[M] = { 0 };
    scanf("%d", &T);
    c = getchar();
    for (i = 0; i < T; i++)
    {
        j = 0;
        while ((c = getchar()) != '\n')
        {
            temp = c - 0;
            s[temp]++;
            if (j == 0)
            {
                L[j] = temp;
                j++;
            }
            else if (temp != L[j-1])
            {
                L[j] = temp;
                j++;
            }
        }
        n = j;
        printf("case #%d:\n",i);
        for (j = 0; j < n; j++)
        {
            if (s[L[j]] > 255)
            {
                printf("%d%c", 255, L[j]);
                s[L[j]] = s[L[j]] - 255;
                printf("%d%c", s[L[j]], L[j]);
                s[L[j]] = 0;
                L[j] = 0;
            }
            else
            {
                printf("%d%c", s[L[j]], L[j]);
                s[L[j]] = 0;
                L[j] = 0;
            }
        }
        printf("\n");

    }
    return 0;
}