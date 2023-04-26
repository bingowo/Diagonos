#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T, x, i, j, len,len2, mer, re;
    char s[165];
    scanf("%d", &T);
    for (x = 0;x < T;x++)
    {
        printf("case #%d:\n", x);
        scanf("%s", s);
        len2=len = strlen(s);
        for (i = len;i < 165;i++)
            s[i] = '0';
        len--;
        
        while (s[len] != '.')
        {
            //re=s[len]-'0';
            j = len;
            re = s[j] - '0';
            while(re!=0||j<len2)                        //这个很关键，不然中间可能就停止了
            {
                mer = (re * 10 + (s[j + 1] - '0')) / 8;
                re = (re * 10 + (s[j + 1] - '0')) % 8;
                s[j] = mer+'0';
                j++;
            }
            len--;
            len2 = j;
        }
        s[len2] = 0;
        puts(s);
    }
    return 0;
}
