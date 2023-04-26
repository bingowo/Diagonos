#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define M 1000000
int main()
{
    char str[M] = { 0 };
    int p[250] = { 0 }, c[250] = { 0 };
    int i = 0, j = 0, t = 0, temp = 0, MAX = 0;
    int L = 0;
    int n = 0, len = 0, start = 0;
    scanf("%s", str);
    n = strlen(str);
    if (n == 1)
        printf("%s\n", str);
    else
    {
        for (i = 0; i < n; i++)
        {
            t = str[i] - 0;
            if (c[t] == 0)
            {
                p[t] = i;
                c[t] = 1;
                len++;
                if (i == n - 1)
                {
                    if (MAX < len)
                    {
                        MAX = len;
                        L = start;
                    }
                }
            }
            else
            {
                if (MAX < len)
                {
                    MAX = len;
                    L = start;
                }
                for (j = start; j < p[t]; j++)
                {
                    temp = str[j] - 0;
                    c[temp] = 0;
                    p[temp] = 0;
                }
                start = p[t] + 1;
                p[t] = i;
                c[t] = 1;
                len = i - start + 1;
            }
        }
        for (i = L; i < L+MAX; i++)
        {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}