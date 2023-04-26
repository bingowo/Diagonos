#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char base64[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
int main()
{
    int N,i;
    scanf("%d\n",&N);
    for(i=0;i<N;i++)
    {
        char str[1024];
        char res[1024];
        char ch;
        int bits=0,ret=0,pos=0,temp=0;
        gets(str);
        int j=0;
        for(j=0;j<strlen(str);j++)
        {
            ch = str[j];
            temp = (ret<<(6-bits))+(ch>>(2+bits));
            res[pos++] = base64[temp];
            bits+=2;
            ret= ch%(1<<bits);
            if(bits == 6)
            {
                res[pos++] = base64[ret];
                bits=0;
                ret=0;
            }
        }
        if(bits == 2)
        {
            res[pos++] = base64[ret<<4];
            res[pos++] = '=';
            res[pos++] = '=';
        }
        else if(bits == 4)
        {
            res[pos++] = base64[ret<<2];
            res[pos++] = '=';
        }
        res[pos++] = '\0';
        printf("case #%d:\n",i);
        printf("%s\n",res);
    }
    return 0;
}
