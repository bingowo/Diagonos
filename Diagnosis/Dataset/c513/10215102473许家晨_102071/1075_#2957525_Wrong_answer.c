#include <stdio.h>
#include <string.h>
int max(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int M, N;
    scanf("%d%d", &M, &N);
    int A[M][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    int res[M][N];
    int trs[M][N];
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == 0 && j == 0)
            {
                res[i][j] = A[i][j];
            }
            else if (i == 0)
            {
                res[i][j] = A[i][j] + res[i][j - 1];
                trs[i][j] = 1;
            }
            else if (j == 0)
            {
                res[i][j] = A[i][j] + res[i - 1][j];
                trs[i][j] = 0;
            }
            else
            {
                res[i][j] = max(res[i][j - 1], res[i - 1][j]) + A[i][j];
                if (res[i][j - 1] > res[i - 1][j])
                    trs[i][j] = 0;
                else
                    trs[i][j] = 1;
            }
        }
    }
    printf("%d\n", res[M - 1][N - 1]);
    char road[M + N - 2];
    i = M - 1, j = N - 1;
    int cnt = 0;
    while (i != 0 || j != 0)
    {
        if (trs[i][j] == 1)
        {
            road[cnt++] = 'R';
            j--;
        }
        else
        {
            road[cnt++] = 'D';
            i--;
        }
    }
    for (i = strlen(road) - 2; i >= 0; i--)
    {
        printf("%c", road[i]);
    }
    return 0;
}