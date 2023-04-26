#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j = 0 ; j < T ; j++)
    {
        printf("case #%d:\n",j);
        int str_len;
        int line_len; //  每行长度
        char s[2001];
        scanf("%d\n",&line_len);
        gets(s);
        str_len=strlen(s);//字符串长度
        int i,l,p,words_len=0,words_count=0;
        for(i = 0 ; s[i] == ' '; i++); //跳过行首空格
        while(i<str_len) //统计每一行的单词数和单词个数
        {
            int start = i;//start变量记录每一行要输出的第一个单词的起始位置
            for( ; words_len + words_count <= line_len && i < str_len ; )
            {
                for(l=0,p=i;s[p]!=' '&& p < str_len ; p++,l++); //查找下一个单词及其长度
                if(words_len+words_count+l<=line_len)
                {
                    words_len+=l;
                    words_count++;
                    for(i=p;s[i]==' ';i++);      //跳过空格
                }
                else break;
            }
            int space=line_len-words_len;   // 计算每行需填充的空格个数
            int m = start ;words_count--;
            while(m < i)//按排版要求输出一行
            {
                while(s[m]!=' ' && m < str_len) putchar(s[m++]);//输出一个单词
                while(s[m] == ' ' && m < str_len)m++;//跳过空格
                if(i == str_len && words_count) putchar(' ');
                else
                {
                    for(p=0;words_count && p < space / words_count;p++)
                        putchar(' ');
                space -= p;
                }
                words_count--;
            }
            putchar('\n');
            }
        }
        return 0;
}
