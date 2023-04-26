#include <stdio.h>
#include <string.h>

char base64_chart[] =
{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};

int main()
{
    int t;
    scanf("%d",&t);
    for(int z = 0; z < t; z++)
    {
        char src[1024], res[1024];
        scanf("%s",src);
        int len = strlen(src);
        int pos = 0;
        int index = 0;
        int bits = 0;
        int ret = 0;
        while(index < len)
        {
            char ch = src[index];
            int cur = (ret << (6 - bits)) + (ch >> (2 + bits));
            res[pos++] = base64_chart[cur];
            index++;
            bits += 2;
            ret = ch % (1 << bits);
            if(bits == 6)
            {
                res[pos++] = base64_chart[ret];
                bits = 0;
                ret = 0;
            }
        }
        if(bits == 2) //最后一组只有1个字符
        {
            res[pos++] = base64_chart[ret << 4];
            res[pos++] = '=';
            res[pos++] = '=';
        }
        else if(bits == 4) //最后一组只有2个字符
        {
            res[pos++] = base64_chart[ret << 2];
            res[pos++] = '=';
        }
        res[pos] = '\0';
        printf("case #%d:\n",z);
        printf("%s\n",res);
    }
    return 0;
}




