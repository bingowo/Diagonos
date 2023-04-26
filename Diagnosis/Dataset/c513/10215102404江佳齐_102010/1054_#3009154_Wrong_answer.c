#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int m=0;m<t;m++)
    {
        int str_len,line_len,i,j,p,start;
        char s[2001];
        scanf("%d",&line_len);
        gets(s);
        gets(s);
        printf("casr #%d:\n",m);
        str_len=strlen(s);
        for(i=0;s[i]==' ';i++);//跳过行首空格
        while(i<str_len)
        {
            //统计每一行输出的单词总长度及单词个数
            start=i;
            int words_len=0,words_count=0,space;
            for(;words_count+words_len<=line_len&&i<str_len;)
            {
                for(j=0,p=i;s[p]!=' '&&p<str_len;p++,j++);//查找下一个单词及其长度
                if(words_count+words_len+j<=line_len)
                {
                    words_count++;words_len+=j;
                    for(i=p;s[i]==' ';i++);//跳过空格
                }
                else break;
            }
            space=line_len-words_len;
            //按照排版要求输出
            j=start;
            words_count--;
            while(j<i)
            {
                while(s[j]!=' '&&j<str_len) putchar(s[j++]);//输出一个单词
                while(s[j]==' '&&j<str_len) j++;//跳过空格
                if(i==str_len&&words_count)
                    putchar(' ');//最后一行，单词之间输出一个空格
                else
                {
                    for(p=0;words_count&&p<space/words_count;p++)
                        putchar(' ');
                    space-=p;
                }
                words_count--;
            }
            putchar('\n');
        }
    }
    return 0;
}
