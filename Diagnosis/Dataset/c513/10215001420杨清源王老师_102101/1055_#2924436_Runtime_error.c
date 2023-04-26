#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[10000];
    scanf("%s",s);
    int start = 0, len = 1, i, t = 0;
    char c;//记录当前字符
    int m[128];
    for( i = 0 ; i < 128 ; i++)
        m[i] = -1;//初始化m，m[i]对应ascii表内的位置
    for( i = 0 ; i < strlen(s) ; i++)
    {
        c = s[i];
        if( m[c] >= t )//如果c在i之前出现过
        {
            t = m[c] + 1;//记录新的起始点
            m[c] = i;//更新字符c的位置
        }
        else
        {
            m[c] = i;//更新字符c的位置
            if( len < i - t + 1)
            {
                start = t;
                len = i - t + 1;
            }
        }
    }

    for( i = 0 ; i < len ; i++)
        printf("%c",s[ start + i ] );
}
