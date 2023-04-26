#include <stdio.h>
#include <string.h>
int main()
{
    char base64_chart[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
    char in[1024],out[1024];//in[]为输入的字符串。out[]为编码后的字符串
    int T,i;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        gets(out);
        int len;
        len=strlen(in);
        int pos,index,bits;//index表示输入的字符串中每个字符的位置
        pos=0;
        index=0;
        bits=0;
        int ret=0;//ret表示要放到高位的数
        while(index<len)
        {
            char ch;
            ch=in[index];
            char chn;//新组成的6bits的二进制串
            chn=(ret<<(6-bits))+(ch>>(2+bits));
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
