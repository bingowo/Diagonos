#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char base64_chart[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
    int T;
    int i,j,k,pos,index,bits,ret,len,cur;
    char ch;
    char src[1024], res[1024];
    scanf("%d",&T);
    for(k=0;k<T;k++)
    {
        gets(src);
        len = strlen(src);
    pos = 0; index = 0; bits = 0;
    ret = 0;
    while(index < len)
    { ch = src[index];
    cur = (ret << (6 - bits)) + (ch >> (2 + bits));
    res[pos++] = base64_chart[cur];
    index++;
    bits += 2;
    ret = ch % (1 << bits);
    if(bits == 6)
    { res[pos++] = base64_chart[ret];
    bits = 0;
    ret = 0; }
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
printf("case #%d:\n",k-1);
for(j=0;j<pos;j++)
{
    printf("%c",res[j]);
}
printf("\n");
    }
    return 0;
}