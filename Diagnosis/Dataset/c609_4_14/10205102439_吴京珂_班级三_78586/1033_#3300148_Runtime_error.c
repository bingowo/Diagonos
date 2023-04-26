#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base64_chart[] =
{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};


int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        char src[105], res[105];
        scanf("%s",src);
        int len = strlen(src);//长度

        int bits = 0;
        int cur=0,ret = 0;//字符表位置
        int ch;//每位

        int j = 0,k = 0;
        while(j < len)
        {
            ch = src[j];
            cur = (ret << (6 - bits)) + (ch >> (2 + bits));
            res[k++] = base64_chart[cur];
            j++;
            bits += 2;
            ret = ch % (1 << bits);
            if(bits == 6)
            {
                res[k++] = base64_chart[ret];
                bits = 0;
                ret = 0;
            }

        }
        if(bits == 2) //最后一组只有1个字符
        {
            res[k++] = base64_chart[ret << 4];
            res[k++] = '=';
            res[k++] = '=';
        }
        else if(bits == 4) //最后一组只有2个字符
        {
            res[k++] = base64_chart[ret << 2];
            res[k++] = '=';
        }
        res[k] = '\0';

        printf("case #%d:\n%s\n",i,res);
    }

    return 0;
}



