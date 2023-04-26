#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[12];
    int solvednum;
    int score;
} stu;

int cmp(stu *a, stu *b)
{
    if (a->score != b->score)
        return b->score - a->score;
    else
    {
        int n = strcmp(a->id, b->id);
        return n;
    }
}

void func()
{
    stu stuarr[510];
    int n, m, g, cnt = 0;
    scanf("%d%d%d", &n, &m, &g);
    int scorearr[11];
    for (int i = 0; i < m; i++)
        scanf("%d", &scorearr[i]);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &stuarr[i].id);
        scanf("%d", &stuarr[i].solvednum);
        stuarr[i].score = 0;
        for (int j = 0; j < stuarr[i].solvednum; j++)
        {
            int qn;
            scanf("%d", &qn);
            stuarr[i].score += scorearr[qn - 1];
        }
        if (stuarr[i].score >= g)
            cnt++;
    }
    qsort(stuarr, n, sizeof(stuarr[0]), cmp);
    printf("%d\n", cnt);
    int k = 0;
    while (stuarr[k].score >= g)
    {
        printf("%s %d\n", stuarr[k].id, stuarr[k].score);
        k++;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int z = 0; z < T; z++)
    {
        printf("case #%d:\n", z);
        func();
    }
    return 0;
}