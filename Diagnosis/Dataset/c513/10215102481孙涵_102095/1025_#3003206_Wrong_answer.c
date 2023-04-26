#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
    char string[20];
    int u;
} ;

typedef struct data S;

int cmp(const void *a, const void *b)
{
    const S *x = a, *y = b;
    if (x->u == y->u)
    {
        return strcmp(x->string, y->string);
    }
    else
    {
        return y->u - x->u;
    }
}

int count_unique(char *buf)
{
    int hash[256] = {0};
    int n = 0;
    for (int i = 0, l = strlen(buf); i < l; ++i)
    {
        if (hash[buf[i]] == 0)
        {
            hash[buf[i]] = 1;
            n++;
        }
    }
    return n;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        S s[100];
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s[i].string);
            s[i].u = count_unique(s[i].string);
        }
        qsort(s, n, sizeof(S), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j < n; j++)
        {
            printf("%s\n", s[j].string);
        }
    }
    return 0;
}