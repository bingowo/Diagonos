#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[12];
    int num[10];
    long long mark;
}student;

int cmp(const void* a, const void* b)
{
    int i = 0;
    student m = *(student*)a, n = *(student*)b;
    if(m.mark != n.mark)
    {
        if(m.mark >= n.mark)
            return -1;
        else
            return 1;
    }
    while(m.name[i] == n.name[i])
        i++;
    return (m.name[i] - '0') - (n.name[i] - '0');
}

int main()
{
    int T, i, n, j;
    int t, m, g, s;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d%d%d", &n, &m, &g);
        int score[m];
        int passnumber = 0;
        int k = 0;
        student stu[n];

        for(j=0; j<m; j++)
            scanf("%d", &score[j]);

        for(j=0; j<n; j++)
        {
            stu[j].mark = 0;
            for(t=0; t<10; t++)
                stu[j].num[t] = 0;
            scanf("%s%d", &stu[j].name, &s);
            for(t=0; t<s; t++)
            {
                scanf("%d", &stu[j].num[t]);
                stu[j].mark += score[stu[j].num[t]];
            }
            if(stu[j].mark >= g)
                passnumber++;
        }

        qsort(stu,n,sizeof(stu[0]),cmp);

        printf("case #%d:\n%d\n", T, passnumber);
        for(j=0; j<passnumber; j++)
            printf("%s %lld\n", stu[j].name, stu[j].mark);

    }

    return 0;
}
