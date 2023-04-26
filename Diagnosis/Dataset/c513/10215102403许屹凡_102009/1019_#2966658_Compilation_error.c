#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    const int *p1 = a, *p2 = b,
    t1 = p2[3] - p1[3],
    t2 = p2[1] - p1[1],
    t3 = p1[2] - p2[2],
    t4 = p1[0] - p2[0];
    if(t1) return t1;
    if(t2) return t2;
    if(t3) return t3;
    if(t4) return t4;
}

int main()
{
    int n, m, a, b, c;
    while (scanf("%d %d", &n, &m) != EOF && !(n == 0 && m == 0))
    {
        int p[n+1][4];
        for (int i = 0; i <= n; i++)
        {
            p[i][0] = i;
            p[i][1] = 0;
            p[i][2] = 0;
            p[i][3] = 0;
        }
        int a, b, c;
        while(m--)
        {
            scanf("%d %d %d", &a, &b, &c);
            if (c == 1)
            {
                p[a][1]++;
                p[b][2]++;
                p[a][3] += 3;
                p[b][3]--;
            }
            if (c == -1)
            {
                p[b][1]++;
                p[a][2]++；
                p[b][3] += 3;
                p[a][3] --;
            }
            if (c == 0)
            {
                p[b][3]++;
                p[a][3]++;
            }
        }
        qsort(p + 1, n, sizeof(p[0]), cmp);
        for (int i = 1; i <= n; i++)
            printf("%d%c", p[i][0], i != n ? ' ' : '\n');
    }
    return 0;
        
}