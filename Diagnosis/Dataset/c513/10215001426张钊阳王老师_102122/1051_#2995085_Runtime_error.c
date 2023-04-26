#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *base64_encode(unsigned char *str);

unsigned char *bae64_decode(unsigned char *code);

int main()
{
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        char s[200];
        scanf("%s",s);
        printf("case #%d:\n",z);
        printf("%s",base64_encode(s));
        printf("\n");

    }
    return 0;
}
unsigned char *base64_encode(unsigned char *str)
{
    long str_len;
    str_len=strlen(str);
    int l=str_len;
    unsigned char res[150];
    int i,j;
    unsigned char *base64_table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int m=l/3;
    int p=l-3*m;

    for(int z=0;z<m;z++)
    {
        for(i=0,j=0;j<3*m;j+=3,i+=4)
    {
        res[4*z+i]=base64_table[str[j]>>2]; //取出第一个字符的前6位并找出对应的结果字符
        res[4*z+i+1]=base64_table[(str[j]&0x3)<<4 | (str[j+1]>>4)];
        res[4*z+i+2]=base64_table[(str[j+1]&0xf)<<2 | (str[j+2]>>6)];
        res[4*z+i+3]=base64_table[str[j+2]&0x3f]; //取出第三个字符的后6位并找出结果字符
    }
    }

    if(p==1)
    {
        res[4*m]=base64_table[(str[3*m]>>2)];
        res[4*m+1]=base64_table[(str[3*m]&0x3)<<4];
        res[4*m+2]='=';
        res[4*m+3]='=';
    }
    if(p==2)
    {
        res[4*m]=base64_table[str[3*m]>>2];
        res[4*m+1]=base64_table[(str[3*m]&0x3)<<4|str[3*m+1]>>4];
        res[4*m+2]=base64_table[str[3*m+2]<<2];
        res[4*m+3]='=';
    }

    strcpy(str,res);
    return str;
}
