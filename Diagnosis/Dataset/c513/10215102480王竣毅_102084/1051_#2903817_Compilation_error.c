#include <stdio.h>
#include <stdlib.h>


int main()
{
    char base64_chart[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
    char src[1024], res[1024];
    len = strlen(src);
    pos = 0; index = 0; bits = 0;
    ret = 0;
    while(index < len)
    {   ch = src[index];
        cur = (ret << (6 - bits)) + (ch >> (2 + bits));
        res[pos++] = base64_chart[cur];
        index++;
        bits += 2;
        ret = ch % (1 << bits);
        if(bits == 6)
        {   res[pos++] = base64_chart[ret];
            bits = 0;
            ret = 0;
        }
    }
    if(bits == 2)
    {
    res[pos++] = base64_chart[ret << 4];
    res[pos++] = '=';
    res[pos++] = '=';
    }
    else if(bits == 4)
    {
    res[pos++] = base64_chart[ret << 2];
    res[pos++] = '=';
    }
    res[pos] = '\0';
    return 0;
}