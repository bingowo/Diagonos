#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
    char num[11];
    int sco;
};

int cmp(const void* a, const void* b)
{
    struct stu *pa = (struct stu*)a;
    struct stu *pb = (struct stu*)b;
    if (pa->sco > pb->sco) return -1;
    else if (pa->sco < pb->sco) return 1;
    else
    {
        return strcmp(pa->num, pb->num);
    }
}

int main()
{
    int T = 0;
    scanf("%d",&T);

    int i = 0;
    for (i = 0; i < T; i++)
    {
        struct stu s[500] = {0};
        int M = 0;
        int N = 0;
        int G = 0;
        scanf("%d %d %d", &N, &M, &G);
        int sco[10] = {0};

        int j = 0;
        for(j = 0; j<M; j++)
        {
            scanf("%d", &sco[j]);
        }

        int num = 0;
        for(j = 0; j<N; j++)
        {
            scanf("%s", s[j].num);
            int n = 0;
            scanf("%d",&n);
            int p = 0;
            for(p = 0; p<n; p++)
            {
                int q = 0;
                scanf("%d", &q);
                s[j].sco += sco[q-1];
            }
            if (s[j].sco >= G)

            {
                num++;
            }
        }
        qsort(s, N, sizeof(s[0]), cmp);
        printf("case #%d:\n", i);
        printf("%d\n", num);
        for(j = 0; j<num; j++)
        {
            printf("%s", s[j].num);
            printf(" %d\n", s[j].sco);
        }

    }
    return 0;
}
