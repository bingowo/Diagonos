#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve()
{
    char str[2001];
    int line_len,i=0,j,p,l,words_len,words_count,space,start,str_len;
    scanf("%d ",&line_len);
    gets(str);
    str_len=strlen(str);
    while(i<str_len)
    {
        while(str[i]==' ')
            i++;
        start=i;
        words_count=0,words_len=0;
        while(words_count+words_len<=line_len)
        {
            for(p=i,l=0;str[p]!=' '&&p<str_len;p++,l++);
            if(words_count+words_len+l<=line_len)
            {
                words_count++;
                words_len+=l;
                for(i=p;str[i]==' '&&i<str_len;i++);
            }
            else
                break;
        }
        space=line_len-words_len;
        j=start;
        words_count--;
        while(j<i)
        {
            while(str[j]!=' '&&j<i)
                putchar(str[j++]);
            for(;str[j]==' '&&j<i;j++);
            if(i==str_len&&words_count)
                putchar(' ');
            else
            {
                for(p=0;words_count&&p<space/words_count;p++)
                    putchar(' ');
                space-=p;
            }
            words_count--;
        }
        printf("\n");
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        solve();
    }
}

