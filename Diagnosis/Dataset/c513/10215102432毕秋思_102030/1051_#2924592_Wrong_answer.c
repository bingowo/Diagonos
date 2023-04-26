#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char base64_chart[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char src[1024],res[1024];
        gets(src);
        int len=strlen(src);
        int pos=0,index=0,bits=0,ret=0;
        while(index<len)
        {
            int ch=src[index];
            int cur=(ret<<(6-bits))+(ch>>(2+bits));
            res[pos++]=base64_chart[cur];
            index++;
            bits+=2;
            ret=ch%(1<<bits);
            if(bits==6)
            {
                res[pos++]=base64_chart[ret];
                bits=0;
                ret=0;
            }
        }
        if(bits==2)
        {
            res[pos++]=base64_chart[ret<<4];
            res[pos++]='=';
            res[pos++]='=';
        }
        else if(bits==4)
        {
            res[pos++]=base64_chart[ret<<2];
            res[pos++]='=';
        }
        res[pos]='\0';
        printf("case #%d:\n",t);
        printf("%s",res);
    }
    return 0;
}
