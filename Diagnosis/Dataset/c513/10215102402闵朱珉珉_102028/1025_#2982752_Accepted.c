#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[100];
    int sum;
} List;

int cmp(const void *a, const void *b)
{
    const List *x = a, *y = b;
    if (x->sum == y->sum)
    {
        return strcmp(x->s, y->s);
    }
    else
    {
        return y->sum - x->sum;
    }
}

int change(char *s)
{
    int q[256] = {0};
    int n = 0;
    for (int i = 0, l = strlen(s); i < l; ++i)
    {
        if (q[s[i]] == 0)
        {
            q[s[i]] = 1;
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
        List p[200];
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", p[i].s);
            p[i].sum = change(p[i].s);
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j < n; j++)
        {
            printf("%s\n", p[j].s);
        }
    }
    return 0;
}
