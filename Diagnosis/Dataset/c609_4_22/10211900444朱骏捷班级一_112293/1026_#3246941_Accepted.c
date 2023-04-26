#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[30];
    int diffnum;
} word;

int getdiff(word x)
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
    word *p1 = (word *)a, *p2 = (word *)b;
    int x;
    if (p1->diffnum != p2->diffnum)
        return p1->diffnum < p2->diffnum;
    else
        return strcmp(p1->id, p2->id);
}

void func()
{
    word arr[110];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &arr[i].id);
        arr[i].diffnum = getdiff(arr[i]);
    }
    qsort(arr, n, sizeof(arr[0]), cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i].id);
    }
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