#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};

int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        printf("case #%d:\n",k);
        char src[101],res[1024];
        scanf("%s",src);
        int len=strlen(src);
        int pos=0,index=0,bits=0,ret=0;
        while(index<len)
        {
            char ch=src[index];
            int cur=(ret<<(6-bits))+(ch>>(2+bits));
            res[pos++]=base[cur];
            index++;
            bits+=2;
            ret=ch%(1<<bits);
            if(bits==6)
            {
                res[pos++]=base[ret];
                bits=0;
                ret=0;
            }
        }
        if(bits==2) //最后一组只有一个字符
        {
            res[pos++]=base[ret<<4];
            res[pos++]='=';
            res[pos++]='=';
        }
        else if(bits==4) //最后一组只有2个字符
        {
            res[pos++]=base[ret<<2];
            res[pos++]='=';
        }
        res[pos]='\0';
        printf("%s\n",res);
    }
    return 0;
}
