#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int i,t=0,str_len,line_len;char s[2001];
    scanf("%d\n",&line_len);
    gets(s);
    str_len=strlen(s);
    for(i=0;s[i]==' ';i++);
    while(i<str_len)
    {
        int start=i;
        int words_len=0,words_count=0;
        int I,p;
        for(;words_len+words_count<=line_len&&i<str_len;)
        {
            for(I=0,p=i;s[p]!=' '&&p<str_len;p++,I++);
            if(words_len+words_count+I<=line_len)
            {
                words_len+=1;words_count++;
                for(i=p;s[i]==' ';i++);
            }
            else break;
        }
        int space=line_len-words_len;
        int j=start;words_count--;
        while(j<i)
        {
            while(s[j]!=' '&&j<str_len)putchar(s[j++]);
            while(s[j]==' '&&j<str_len)j++;
            if(i==str_len&&words_count)
                putchar(' ');
            else
            {
                for(p=0;words_count&&p<space/words_count;p++)
                    putchar(' ');
                space-=p;
            }
            words_count--;
        }putchar('\n');
    }
}