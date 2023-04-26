#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; i++) {
        char s[50] = {'0'};
        scanf("%s",s);
        int a[50] = {0};
        int len = strlen(s) - 1,j = 0;
        //将字符串转换为数字
        while(len >= 0){
            if (s[len] == '-') a[j++] = -1;
            if (s[len] == '0') a[j++] = 0;
            if (s[len] == '1') a[j++] = 1;
            len--;
        }
        int ans = 0; //存放最终结果
        while (j) {
            ans = ans * 3 + a[--j];
        }

        //输出
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}
