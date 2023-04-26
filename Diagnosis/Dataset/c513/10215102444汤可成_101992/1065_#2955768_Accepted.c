#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, n, m, x;
    scanf("%d %d %d %d", &a, &n, &m, &x);
    int up[21] = {0};
    int down[21] = {0};
    int sum[21] = {0};

    up[1] = a;
    down[1] = 0;
    sum[1] = a;
    sum[2] = a;

    for(int j = 0; j<=m; j++)  //车上人数单调增所以第二站上车人数不会超过m
    {
        up[2] = j;
        down[2] = j;
        for(int i = 3; i<n; i++)
        {
            up[i] = up[i-1] + up[i-2];
            down[i] = up[i-1];
            sum[i] = sum[i-1] + up[i] - down[i];
        }
        if(sum[n-1] == m)
        {
            printf("%d\n", sum[x]);
            break;
        }
    }
    return 0;
}
