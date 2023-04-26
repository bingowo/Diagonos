#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
     int str_len;
     int  line_len;
     char s[2001];
     scanf("%d\n",&line_len);
     gets(s);
     str_len=strlen(s);
     int i;
    for(i=0;s[i]==' ';i++);
    int start=i;
    int words_len=0,words_count=0;
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
    int space=line_len-words_len;
    int j=start;
    words_count--;
    while(j<i)
    {
       while(s[j]!=' '&&j<str_len) putchar(s[j++]);
       while(s[j]==' '&&j<str_len) j++;
       if(i==str_len&&words_count)
            putchar(' ');
       else
      {
        int p;
        for(p=0;words_count&&p<space/words_count;p++)
                putchar(' ');
                space-=p;
       }
      words_count--;
    }
        putchar('\n');

    return 0;
}