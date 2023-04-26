#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[40];
    int num;
    int has_num; // 有数字为0，没数字为1
} node;

int cmp(const void *a, const void *b)
{
    node *x = (node *)a;
    node *y = (node *)b;
    if (x->has_num != y->has_num)
        return x->has_num - y->has_num;
    else
    {
        if (x->num != y->num)
            return x->num - y->num;
        else
            return strcmp(x->s, y->s);
    }
}

void setvalue(char *s, node *a)
{
    strcpy(a->s, s);
    a->num = 0;
    a->has_num = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            a->has_num = 1;
            a->num = a->num * 10 + (s[i] - '0');
        }
    }
}

int main()
{
    char s[40];
    node A[110];
    int k = 0;
    while (scanf("%s", s) == 1)
        setvalue(s, &A[k++]);
    qsort(A, k, sizeof(node), cmp);
    for (int i = 0; i < k; i++)
    {
        printf("%s", A[i].s);
        if (i != k - 1)
            printf(" ");
    }
    return 0;
}