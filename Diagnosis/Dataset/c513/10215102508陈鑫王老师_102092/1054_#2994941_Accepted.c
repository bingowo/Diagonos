#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int slen,llen;
        char s[2001];
        scanf("%d\n",&llen);
        gets(s);
        slen=strlen(s);
        printf("case #%d:\n",i);
        int words_len,words_count,space,j,start,l,p;
        for(j=0;s[j]==' ';j++);
        while(j<slen)
        {
            start=j;
            words_len=0,words_count=0;
            for(;words_len+words_count<=llen&&j<slen;)
            {
                for(l=0,p=j;s[p]!=' '&&p<slen;p++,l++);
                if(words_count+words_len+l<=llen)
                {
                    words_len+=l;
                    words_count++;
                    for(j=p;s[j]==' ';j++);
                }
                else break;
            }
            space=llen-words_len;
            int k=start;
            words_count--;
            while(k<j)
            {
                while(s[k]!=' '&&k<slen)putchar(s[k++]);
                while(s[k]==' '&&k<slen)k++;
                if(j==slen&&words_count)
                    putchar(' ');
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
