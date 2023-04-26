#include <stdio.h>
#include <string.h>
char base64_chart[] =
{ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=" };
int main()
{
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++)
    {
        char s[100], end[400];
        scanf("%s", s);
        int len = strlen(s);
        int i = 0,j = 0;
        int bits = 0,ret = 0;
        while (i < len)
        {
            char ch = s[i];
            int cur = (ret << (6 - bits)) + (ch >> (2 + bits));
            end[j++] = base64_chart[cur];
            i++;
            bits += 2;
            ret = ch % (1 << bits);
            if (bits == 6)//三个字符为一组
            {
                end[j++] = base64_chart[ret];
                bits = 0;
                ret = 0;
            }
        }
        if (bits == 2) //最后一组只有1个字符
        {
            end[j++] = base64_chart[ret << 4];
            end[j++] = '=';
            end[j++] = '=';
        }
        else if (bits == 4) //最后一组只有2个字符
        {
            end[j++] = base64_chart[ret << 2];
            end[j++] = '=';
        }
        end[j] = '\0';
        printf("case #%d:\n", z);
        printf("%s\n", end);
    }
    return 0;
}