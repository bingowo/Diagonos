#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int str_len;
     int  line_len;     //每行长度
     char s[2001];
     scanf("%d\n",&line_len);
     gets(s);
     str_len=strlen(s);   
     int i;
     for(i=0;s[i]==' ';i++);   //跳过行首空格
while(i<str_len)
{
     int start=i;          //start变量记录每一行要输出的第一个单词的起始位置
int words_len=0,words_count=0;
for(;words_len+words_count<=line_len&&i<str_len;) 
{
    int l,p;
	for(l=0,p=i;s[p]!=' '&&p<str_len;p++,l++); //查找下一个单词及其长度   
    if(words_len+words_count+l<=line_len)
     {  
         words_len+=l;words_count++;
         for(i=p;s[i]==' ';i++);      //跳过空格
      }
     else break;
}
int space;
space=line_len-words_len;   
int j=start;      words_count--;
while(j<i)       //按照排版要求输出一行
{
      while(s[j]!=' '&&j<str_len) putchar(s[j++]);  //输出一个单词
       while(s[j]==' '&&j<str_len) j++;   //跳过空格
       if(i==str_len&&words_count)  //最后一行，单词之间输出一个空格
            putchar(' ');                                                  
       else    //其它行的空格在单词之间尽可能均匀分布，尽可能靠右
      {   
	  int p;
	  for(p=0;words_count&&p<space/words_count;p++)
                 putchar(' ');    
           space-=p;
       }
      words_count--;
}    putchar('\n');}

return 0;