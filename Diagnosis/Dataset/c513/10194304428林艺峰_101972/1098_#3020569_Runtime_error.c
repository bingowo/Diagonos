#include<stdio.h>
#include<string.h>
int main(){
    int t, i, j;
    scanf("%d", &t);
    for(i = 0; i < t; ++i){
        char s[110];
        scanf("%s", s);
        int l = strlen(s);
        int cnt[4] = {0}, tot[4] = {0}, ans[4];
        for(j = 0; j < l; ++j){
            ++tot[j % 4];
            switch(s[j]){
                case 'R': ++cnt[0]; ans[0] = j % 4; break;
                case 'B': ++cnt[1]; ans[1] = j % 4; break;
                case 'Y': ++cnt[2]; ans[2] = j % 4; break;
                case 'G': ++cnt[3]; ans[3] = j % 4; break;
            }
        }
        printf("case #%d:\n%d %d %d %d\n", i, tot[ans[0]] - cnt[0], tot[ans[1]] - cnt[1], tot[ans[2]] - cnt[2], tot[ans[3]] - cnt[3]);
    }
    return 0;
}