#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 210
#define MAX 1000000007
int subint(char* ch, int l, int r)
{
    int s = 0;
    for (int i = l; i <= r; i++) {
    s *= 10;
    s += ch[i] - '0';
    s %= MOD;
}
return s;
}
int main()
{
    char ch[101];
    scanf("%s", ch);
    int f[100][MOD] = {0};
    for (int i = 0; i < strlen(ch); i++)
    {
        f[i][subint(ch, 0, i)] += 1;
        f[i][subint(ch, 0, i)] %= MAX;
        for (int j = 0; j < i; j++)
        {
            int tmp = subint(ch, j + 1, i);
            for (int k = 0; k < MOD; k++)
            {
                f[i][(k + MOD + tmp)%MOD] += f[j][k];
                f[i][(k + MOD + tmp)%MOD] %= MAX;
                f[i][(k + MOD - tmp)%MOD] += f[j][k];
                f[i][(k + MOD - tmp)%MOD] %= MAX;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < MOD; i++)
    {
        if (!(i%2) || !(i%3) || !(i%5) || !(i%7))
        {
            ans += f[strlen(ch) - 1][i];
            ans %= MAX;
        }
    }
    printf("%d\n", ans);
}
