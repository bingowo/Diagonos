#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    char base64_chart[] ={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
    char src[1024], res[1024];
    for(int i=0;i<T;i++)
    {
        scanf("%s",src);
        int len = strlen(src);
        char ch;
        int pos = 0,index = 0,bits=0,ret = 0;
        int cur;
        while(index < len)
        {
            ch = src[index];
            cur = (ret << (6 - bits)) + (ch >> (2 + bits));
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
        printf("case #%d:\n",i);
        int l=strlen(res);
        for(int j=0;j<l;j++)printf("%c",res[j]);
        printf("\n");
    }
    return 0;
}