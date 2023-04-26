#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[31];
    long long number;
}S;

int cmp(const void *a, const void *b)
{
    S *A = (S *)a;
    S *B = (S *)b;

    if (A -> number == B -> number)
        return strcmp(A -> s, B -> s);
    else
        return (A -> number) - (B -> number);
}

int main()
{
    S str[101];

    for(int i = 0; i < 101; i++)  str[i].number = -1;

    int j = 0;

    while(scanf("%s", str[j].s) != EOF)
    {
        int len = strlen(str[j].s);
        long long num = 0;
        int flag = 0;

        for(int k = 0; k < len; k++)
        {
            if(str[j].s[k] >= '0' && str[j].s[k] <= '9')
            {
                flag = 1;
                num = num * 10 + (str[j].s[k] - '0');
            }
        }

        if(flag == 1)  str[j].number = num;
        else  str[j].number = -1;

        j++;
    }

    qsort(str, j, sizeof(S), cmp);

    printf("%s", str[0].s);
    for (int i = 1; i < j; i++)
    {
        printf(" %s", str[i].s);
    }

    return 0;
}