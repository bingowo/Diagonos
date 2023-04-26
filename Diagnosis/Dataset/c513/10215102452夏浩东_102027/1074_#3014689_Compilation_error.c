#include <stdio.h>
#include <string.h>
int main()
{
    int cnt=0; scanf("%d",&cnt);
    for(int mm=0;mm<cnt;mm++){
        char ch[101];
        scanf("%s", ch);
        int f[100][MOD] = {0};
        for (int i = 0; i < strlen(ch); i++) {
            f[i][subint(ch, 0, i)] += 1;
            f[i][subint(ch, 0, i)] %= MAX;
            for (int j = 0; j < i; j++) {
                int tmp = subint(ch, j + 1, i);
                for (int k = 0; k < MOD; k++) {
                    f[i][(k + MOD + tmp)%MOD] += f[j][k];
                    f[i][(k + MOD + tmp)%MOD] %= MAX;
                    f[i][(k + MOD - tmp)%MOD] += f[j][k];
                    f[i][(k + MOD - tmp)%MOD] %= MAX;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < MOD; i++) {
            if (!(i%2) || !(i%3) || !(i%5) || !(i%7)) {
                ans += f[strlen(ch) - 1][i];
                ans %= MAX;
            }
        }
        printf("%d\n", ans);
    }
}