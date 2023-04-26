#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char base64_chart[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char src[1024], res[1024];
        gets(src);
        int len=strlen(src);
        int pos=0,index=0,bits=0;
        int ret=0;
        while(index<len)
        {
            int ch=src[index];
            int cur=(ret<<(6-bits))+(ch>>(2+bits));
            res[pos++]=base64_chart[cur];
            index++;
            bits+= 2;
            ret=ch%(1<<bits);
            if(bits == 6)
            {
                res[pos++] = base64_chart[ret];
                bits = 0;
                ret = 0;
            }
        }
        if(bits == 2)      //最后一组只有1个字符
        {
            res[pos++] = base64_chart[ret << 4];
            res[pos++] = '=';
            res[pos++] = '=';
        }
        else if(bits == 4)    //最后一组只有2个字符
        {
            res[pos++] = base64_chart[ret << 2];
            res[pos++] = '=';
        }
        res[pos] = '\0';
        printf("case #%d:\n%s\n",i,res);
    }
    return 0;
}
