#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char s[30] = {0};

typedef struct {
    char w[100];
}node;

int find(char c)
{
    for(int i = 0;i < 26;i++)
    {
        if(c == s[i])
            return i;
    }
    return 0;
}

int cmp(const void *a,const void *b)
{
    node *pa = (node*)a;
    node *pb = (node*)b;
    int len1 = strlen(pa->w);
    int len2 = strlen(pb->w);
    int max = len1 <= len2 ? len1 : len2;
    for(int i = 0;i < max;i++)
    {
        int res1 = find(toupper(pa->w[i]));
        int res2 = find(toupper(pb->w[i]));
        if(res1 != res2)
            return res1 - res2;
    }
    return len1 - len2;
}

int main()
{
    while((scanf("%s",s)) != EOF)
    {
        node ch[100];
        int cnt = 0;
        char word[20] = {0};
        char c;
        int sig = 1;
        while(sig)
        {
            scanf("%s%c",word,&c);
            if(c == '\n')
                sig = 0;
            memset(ch[cnt].w,'\0',sizeof(ch[cnt].w));
            strcpy(ch[cnt++].w,word);
            memset(word,'\0',sizeof(word));
        }
        qsort(ch,cnt,sizeof(ch[0]),cmp);
        for(int i = 0;i < cnt;i++)
        {
            printf("%s%c",ch[i].w,i == cnt-1 ? '\n' : ' ');
        }
        memset(s,'\0',sizeof(s));
    }

    return 0;
}