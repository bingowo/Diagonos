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

void func()
{
    Word a[1000] = {'\0', 0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &a[i].id);
        a[i].diff = getDiff(a[i]);
    }
    qsort(a, n, sizeof(a[0]), cmp);
    for (int i = 0; i < n; i++)
        printf("%s\n", a[i].id);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        func();
    }
    return 0;
}