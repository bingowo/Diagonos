#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int str_len；
     int  line_len;     
     char s[2001];
     scanf("%d\n",&line_len);
     gets(s);
     str_len=strlen(s); 
     int words_len,words_count,space;
     for(i=0;s[i]==' ';i++); 
while(i<str_len)
{
    start=i;  
    words_len=0,words_count=0；
    start=i;         
words_len=0,words_count=0；
for(;words_len+words_count<=line_len&&i<str_len;) 
{
    for(l=0,p=i;s[p]!=‘ ’&&p<str_len;p++,l++); 
    if(words_len+words_count+l<=line_len)
     {  
         words_len+=l;words_count++;
         for(i=p;s[i]==‘ ’;i++);     
      }
     else break;
}
space=line_len-words_len;
}
j=start;      words_count--;

while(j<i)       //按照排版要求输出一行

{

      while(s[j]!=‘ ’&&j<str_len) putchar(s[j++]);  //输出一个单词

       while(s[j]==‘ ’&&j<str_len) j++;   //跳过空格

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