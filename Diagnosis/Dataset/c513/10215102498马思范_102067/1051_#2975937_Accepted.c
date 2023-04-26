#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char base64[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[101];
        char result[2000];
        scanf("%s",s);
        int len= strlen(s);
        int pos = 0, index = 0, bits = 0;
        int ret = 0;
        while(index < len)
        {   int ch = s[index];
            int cur = (ret << (6 - bits)) + (ch >> (2 + bits));
            result[pos++] = base64[cur];
            index++;
            bits += 2;
            ret = ch % (1 << bits);
            if(bits == 6)
            {   result[pos++] = base64[ret];
                bits = 0;
                ret = 0;
            }
        }
        if(bits == 2)
        {
            result[pos++] = base64[ret << 4];
            result[pos++] = '=';
            result[pos++] = '=';
        }
        else if(bits == 4)
        {
            result[pos++] = base64[ret << 2];
            result[pos++] = '=';
        }
        result[pos] = '\0';
        printf("case #%d:\n",i);
        printf("%s\n",result);
    }
    return 0;
}
