#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stu
{
    char name[12];
    int sum;
} Stu;

int cmp(const void *a, const void *b)
{
    struct Stu *x = a, *y = b;
    if(x->sum == y->sum) {
        return strcmp(x->name, y->name);
    } else {
        return y->sum - x->sum;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    int i, j, k;
    int N, M, G, num, que;
    for (i = 0; i < T; i++)
    {
        int score[11];
        struct Stu stus[500];  
        int cnt = 0;
        printf("case #%d:\n", i);
        scanf("%d %d %d", &N, &M, &G);
        for (j = 1; j <= M; j++)
        {
            scanf("%d", &score[j]);
        }
        for (j = 0; j < N; j++)
        {
            scanf("%s", stus[j].name);
            stus[j].sum = 0;
            scanf("%d", &num);
            for (k = 0; k < num; k++)
            {
                scanf("%d", &que);
                stus[j].sum += score[que];
            }
            if (stus[j].sum >= G)
            {
                cnt++;
            }
        }
        qsort(stus, N, sizeof(struct Stu), cmp);
        printf("%d\n", cnt);
        for (j = 0; j < cnt; j++)
        {
            printf("%s %d\n", stus[j].name, stus[j].sum);
        }
    }
    return 0;
}
