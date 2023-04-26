#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[12];//学号
    int score;//分数
} S;

int cmp(void const *_a, void const *_b) 
{
    S const *a = (S const *)_a;
    S const *b = (S const *)_b;
    if (a->score == b->score)
        return strcmp(a->id, b->id);
    return b->score - a->score;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) 
    {
        int n, m, g;
        scanf("%d %d %d", &n, &m, &g);
        int points[11];//第1题到第m题的分值
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &points[j]);
        }
        S s1[500];
        for (int j = 0; j < n; ++j)
        {
            int s;//s为答题的题号
            s1[j].score = 0;
            scanf("%s %d", s1[j].id, &s);
            for (int k = 0; k < s; k++) 
            {
                int solve;
                scanf("%d", &solve);
                s1[j].score += points[solve];//计算每个学生的分数
            }
        }
        qsort(s1, n, sizeof(S), cmp);
        int pass = 0;
        while (s1[pass].score >= g)
        {
            ++pass;
        }
        printf("case #%d:\n%d\n", i, pass);
        for (int j = 0; j < pass; j++)
            printf("%s %d\n", s1[j].id, s1[j].score);
    }
}
