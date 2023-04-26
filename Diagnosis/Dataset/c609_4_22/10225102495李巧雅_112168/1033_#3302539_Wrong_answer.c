#include <stdio.h>
#include <string.h>
int main()
{
    char base64_chart[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
    char in[1024],out[1024];//in[]为输入的字符串。out[]为编码后的字符串
    int T,i;
    for(i=0;i<T;i++)
    {
        gets(out);
        int len;
        len=strlen(in);
        int pos,index,bits;
        pos=0;
        index=0;
        bits=0;
        int ret=0;
        while(index<len)
        {
            char ch;
            ch=in[index];
            char cur;
            cur=(ret<<(6-bits))+(ch>>(2+bits));
            index++;
            bits+=2;
            ret=ch%(1<<bits);
            if(bits==6)
            {
                out[pos++]=base64_chart[ret];
                bits=0;
                ret=0;
            }
        }
        if(bits==2)
        {
            out[pos++]=base64_chart[ret<<4];
            out[pos++]="=";
            out[pos++]="=";
        }
        else if(bits==4)
        {
            out[pos++]=base64_chart[ret<<2];
            out[pos++]="=";
        }
        out[pos]='\0';
        printf("case #%d:\n",i);
        printf("%s\n",out);
    }
}
