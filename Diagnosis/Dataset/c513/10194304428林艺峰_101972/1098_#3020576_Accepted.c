#include<stdio.h>
#include<string.h>
char str[110], cnt[10], tot[10], ans[10];
int main(){
    int t, i, j;
    scanf("%d", &t);
    for(i = 0; i < t; ++i){
        scanf("%s", &str);
        int l = strlen(str);
        for(j = 0; j < 4; ++j){
        	cnt[j] = 0;	tot[j] = 0;	ans[j] = 0;
		}
        for(j = 0; j < l; ++j){
            ++tot[j % 4];
            switch(str[j]){
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