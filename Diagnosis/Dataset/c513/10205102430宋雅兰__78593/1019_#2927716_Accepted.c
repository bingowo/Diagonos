#include <stdio.h>
#include<stdlib.h>
int cmp(const void *q1, const void *q2)
{
    int *a = (int *)q1;
    int *b = (int *)q2;
    if (a[1] == b[1])
    {
        if(a[2]==b[2]){
            if(a[3]==b[3])
                return a[0]-b[0];
            return a[3]-b[3];
        }
        return b[2]-a[2];
    }
    return b[1] - a[1];
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m))
    {
        int jl[11][4] = {0};
        if (n == 0 && m == 0)
            break;
        for(int j=1;j<=n;j++)
        jl[j][0]=j;
        int i;
        for (i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (c == 1)
            {
                jl[a][1] += 3;
                jl[b][1] -= 1;
                jl[a][2]++;
                jl[b][3]++;
            }
            else if (c == -1)
            {
                jl[a][1] -= 1;
                jl[b][1] += 3;
                jl[a][3]++;
                jl[b][2]++;
            }
            else
            {
                jl[a][1]++;
                jl[b][1]++;
            }
        }
        qsort(jl+1, n, sizeof(jl[0]), cmp);
        for (i = 1; i < n; i++)
            printf("%d ", jl[i][0]);
        printf("%d\n", jl[i][0]);
    }
    return 0;
}