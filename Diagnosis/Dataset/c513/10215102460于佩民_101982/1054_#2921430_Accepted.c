#include <stdio.h>
#include <string.h>

int main(){
    int str_len,i,start,l,p,space,j,Num,Now=0;
    int line_len,words_len,words_count;
    scanf("%d",&Num);
    while(Now<Num){
        char s[2001];
        scanf("%d\n",&line_len);
        gets(s);
        str_len=strlen(s);
        for(i=0;s[i]==' ';i++);
        printf("case #");
        printf("%d:\n",Now);
        while(i<str_len)
        {
            start=i;
            words_len=0,words_count=0;
            for(;words_len+words_count<=line_len&&i<str_len;)
            {
                for(l=0,p=i;s[p]!=' '&&p<str_len;p++,l++);
                if(words_len+words_count+l<=line_len)
                {
                    words_len+=l;words_count++;
                    for(i=p;s[i]==' ';i++);
                }
                else break;
            }
            space=line_len-words_len;
            j=start; words_count--;
            while(j<i)
            {
                while(s[j]!=' '&&j<str_len) putchar(s[j++]);
                while(s[j]==' '&&j<str_len) j++;
                if(i==str_len&&words_count)
                    putchar(' ');
                else
                { for(p=0;words_count&&p<space/words_count;p++)
                        putchar(' ');
                    space-=p;
                }
                words_count--;
            } putchar('\n');
        }Now++;}
    return 0;
}