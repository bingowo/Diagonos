#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int r=0;r<T;r++)
    {
        int str_len;
     int  line_len;
     char s[2001];
     scanf("%d\n",&line_len);
     gets(s);
     str_len=strlen(s);
     printf("case #%d:\n",r);
     int words_len,words_count,space;
     int i;
     for(i=0;s[i]==' ';i++);
     int start;
while(i<str_len)
{
    start=i;
    words_len=0,words_count=0;
    start=i;
words_len=0,words_count=0;
for(;words_len+words_count<=line_len&&i<str_len;)
{
    int l,p;
    for(l=0,p=i;s[p]!=' '&&p<str_len;p++,l++);
    if(words_len+words_count+l<=line_len)
     {
         words_len+=l;words_count++;
         for(i=p;s[i]==' ';i++);
      }
     else break;
}
space=line_len-words_len;
int j=start;      words_count--;
while(j<i)
{
      while(s[j]!=' '&&j<str_len) putchar(s[j++]);
       while(s[j]==' '&&j<str_len) j++;
       if(i==str_len&&words_count)
            putchar(' ');
       else
      {   int p;
          for(p=0;words_count&&p<space/words_count;p++)
                 putchar(' ');
           space-=p;
       }
      words_count--;
}    putchar('\n');
}
    }
}
