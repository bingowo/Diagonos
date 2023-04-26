#include <stdio.h>
#include<stdlib.h>
int cmp(const void *q1, const void *q2)
{
    int *a = (int *)q1;
    int *b = (int *)q2;
    if (a[1] == b[1])
        return b[1] - a[1];
    return a[0] - b[0];
}
int main()
{
    int n, m;
    int jl[11][2] = {0};
    while (scanf("%d%d", &n, &m))
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (c == 1)
            {
                jl[a][1] += 3;
                jl[b][1] -= 1;
            }
            else if (c == -1)
            {
                jl[a][1] -= 1;
                jl[b][1] += 3;
            }
            else
            {
                jl[a][1]++;
                jl[b][1]++;
            }
        }
        qsort(jl, n, sizeof(jl[0]), cmp);
        for (int i = 1; i < n; i++)
            printf("%d ", jl[i][0]);
        printf("%d\n", jl[n][0]);
    }
    return 0;
}