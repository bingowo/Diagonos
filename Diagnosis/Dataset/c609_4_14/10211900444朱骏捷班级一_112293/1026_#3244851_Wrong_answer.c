#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[30];
    int diff;
} Word;

int getDiff(Word x)
{
    int flag[26] = {0};
    int cnt = 0;
    for (int i = 0; x.id[i] != '\0'; i++)
    {
        if (flag[x.id[i] - 'A'] == 0)
            cnt++;
        flag[x.id[i] - 'A']++;
    }
    return cnt;
}

int cmp(const void *a, const void *b)
{
    Word *p1 = (Word *)a, *p2 = (Word *)b;
    int x;
    return (x = p2->diff - p1->diff) ? x : strcmp(p1->id, p2->id);
}

void func();

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        Word a[1000] = {'\0', 0};
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%s", &a[j].id);
            a[j].diff = getDiff(a[j]);
        }
        qsort(a, n, sizeof(a[0]), cmp);
        printf("case #%d\n", i);
        for (int j = 0; j < n; j++)
            printf("%s\n", a[j].id);
    }
    return 0;
}