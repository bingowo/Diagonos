#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base64_chart[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};

int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        char src[101] = {0};
        char res[200] = {0};
        scanf("%s", src);
        int len = strlen(src);
        int pos = 0, index = 0, bits = 0;
        int ret = 0;
        int cur = 0;
        printf("case #%d:\n", i);
        while(index<len)
        {
            char ch = src[index];
            cur = (ret<<(6-bits))+(ch>>(2+bits));
            res[pos++] = base64_chart[cur];
            bits += 2;
            index++;
            ret = ch%(1<<bits);
            if(bits == 6)
            {
                res[pos++] = base64_chart[ret];
                bits = 0;
                ret = 0;
            }
        }
        if(bits == 2)
        {
            res[pos++] = base64_chart[ret<<4];
            res[pos++] = '=';
            res[pos++] = '=';
        }
        else if(bits == 4)
        {
            res[pos++] = base64_chart[ret<<2];
            res[pos++] = '=';
        }
        res[pos] = 0;
        printf("%s\n", res);
    }
    return 0;
}
