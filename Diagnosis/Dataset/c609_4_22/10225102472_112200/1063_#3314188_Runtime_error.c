#include <stdio.h>

int main()
{
    int a, n, m, x;
    int t, i, answer;
    int su[25]={0}, sv[25]={0}, v[25]={0};

    scanf("%d%d%d%d", &a, &n, &m, &x);

    v[1] = 0, v[2] = 1;
    su[1] = su[2] = 1;
    sv[1] = sv[2] = 0;

    for(i = 3; i <= n-1; i++)
    {
        v[i] = v[i-1] + v[i-2];
        su[i] = su[i-1] + v[i-1] - v[i-2];
        sv[i] = sv[i-1] + v[i] - v[i-1];
    }

    t = (m - su[n-1]*a) / sv[n-1];
    answer = su[x]*a + sv[x]*t;

    printf("%d", answer);
    return 0;
}
