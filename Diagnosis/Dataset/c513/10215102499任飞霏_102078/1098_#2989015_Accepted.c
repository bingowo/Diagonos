#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//算法巧妙，大佬版代码
//因为四个不一样，则可以得出每四个彩灯顺序是一样的，即第一第五相同，第二第六相同
//因此只要分别找到%4后相等位置的彩灯，就可以确定顺序


int main()
{
    int T,j;
    scanf("%d", &T);
    for (j = 0; j<T; j++){
        char s[101];
        scanf("%s", s);
        int len = strlen(s), i;
        int cnt[4] = {0}, tot[4] = {0}, ans[4]={0};
        for (i = 0; i < len; ++i){
            ++tot[i % 4];       //位置i上的灯应该有几个
            switch(s[i]){
                //cnt是知道的灯的数量，ans是位置号，因此tot[ans[i]]为i位上应该有的总量
                case 'R': ++cnt[0]; ans[0] = i % 4; break;
                case 'B': ++cnt[1]; ans[1] = i % 4; break;
                case 'Y': ++cnt[2]; ans[2] = i % 4; break;
                case 'G': ++cnt[3]; ans[3] = i % 4; break;
            }
        }
        printf("case #%d:\n%d %d %d %d\n",j,tot[ans[0]] - cnt[0],
        tot[ans[1]] - cnt[1],tot[ans[2]] - cnt[2], tot[ans[3]] - cnt[3]);
    }
    return 0;
}
