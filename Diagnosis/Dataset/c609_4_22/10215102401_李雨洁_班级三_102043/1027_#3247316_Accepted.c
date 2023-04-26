#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student {
    int score;
    char id[11];
};
int cmp(const void* _a, const void* _b)
{
    struct student* a = (struct student*)_a;
    struct student* b = (struct student*)_b;
    if (a->score != b->score) return b->score - a->score;
    else return strcmp(a->id, b->id);       
}
int main()
{
    int t;
    scanf("%d", &t);
    int n,m,g;//n学生人数，m考试题目，g分数线
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &n, &m, &g);
        int points[11];//第1题到第m题的分值
        for (int j = 1; j <= m; ++j) scanf("%d", &points[j]);
        struct student s1[500];
        for (int j = 0; j < n; ++j)
        {
            int s;
            s1[j].score = 0;
            scanf("%s %d", s1[j].id, &s);
            for (int k = 0; k < s; k++)
            {
                int solve;
                scanf("%d", &solve);
                s1[j].score += points[solve];
            }
        }
        qsort(s1, n, sizeof(s1[0]), cmp);
        int pass = 0;
        while (s1[pass].score >= g) pass++;
        printf("case #%d:\n%d\n", i, pass);
        for (int j = 0; j < pass; j++)
            printf("%s %d\n", s1[j].id, s1[j].score);
    }
    return 0;
}