#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int h=0;h<n;h++)
    {
     printf("case #%d:\n",h);
     int str_len;
     int  line_len;     //每行长度
     char s[2001];
     scanf("%d\n",&line_len);
     gets(s);
     str_len=strlen(s);   //字符串长度
     int words_len,words_count,space;
     for(i=0;s[i]==' ';i++);   //跳过行首空格
     while(i<str_len)
    {
    start=i;   //start记录每一行要输出的第一个单词的起始位置
    words_len=0,words_count=0；
    //统计每一行要输出的单词总长度words_len;
    for(;words_len+words_count<=line_len&&i<str_len;) 
     {
    for(l=0,p=i;s[p]!=' '&&p<str_len;p++,l++); //查找下一个单词及其长度   
    if(words_len+words_count+l<=line_len)
     {  
         words_len+=l;words_count++;
         for(i=p;s[i]==' ';i++);      //跳过空格
      }
     else break;
     }
space=line_len-words_len;   //计算每行需填充的空格个数
//按照排版要求输出每一行；
j=start;      words_count--;
while(j<i)       //按照排版要求输出一行
{
      while(s[j]!=' '&&j<str_len) putchar(s[j++]);  //输出一个单词
       while(s[j]==' '&&j<str_len) j++;   //跳过空格
       if(i==str_len&&words_count)  //最后一行，单词之间输出一个空格
            putchar(' ');                                                  
       else    //其它行的空格在单词之间尽可能均匀分布，尽可能靠右
      {   for(p=0;words_count&&p<space/words_count;p++)
                 putchar(' ');    
           space-=p;
       }
      words_count--;
}    putchar('\n');

}   
        
    }
    return 0;
}