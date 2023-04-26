#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> //abs(long long ,long long)

int main()
{
        char s[1005];
        char ans[2222];
        scanf("%s",s);
        for (int i = 0; s[i] != 0; i++)
            s[i] = toupper(s[i]);//小写转大写,头文件ctype.h
        int left = 1100, right = 1101;
        ans[left] = s[0];
        ans[right] = 0;
        for (int i = 1; s[i] != 0; i++)
        {
            if(s[i] >= ans[left])
                ans[--left] = s[i];
            else
                ans[right++] = s[i];
        }
        ans[right]=0;//结尾记得标记结束符“\0”
        printf("%s\n", ans+left);//从第left个开始输出
        return 0;
}
