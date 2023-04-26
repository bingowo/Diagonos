#include <stdio.h>
#include <string.h>

int main()
{
    int cas, t;
    scanf("%d", &cas);
    for (t = 0; t < cas; ++t){
        char s[101];
        scanf("%s", s);
        int len = strlen(s), i;
        int cnt[4] = {0}, tot[4] = {0}, ans[4];
        for (i = 0; i < len; ++i){
            ++tot[i % 4];
            switch(s[i]){
                case 'R': ++cnt[0]; ans[0] = i % 4; break;
                case 'B': ++cnt[1]; ans[1] = i % 4; break;
                case 'Y': ++cnt[2]; ans[2] = i % 4; break;
                case 'G': ++cnt[3]; ans[3] = i % 4; break;
            }
        }
        printf("case #%d:\n%d %d %d %d\n", t, tot[ans[0]] - cnt[0], tot[ans[1]] - cnt[1], tot[ans[2]] - cnt[2], tot[ans[3]] - cnt[3]);
    }
    return 0;
}