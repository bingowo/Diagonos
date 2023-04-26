#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define len 35

typedef struct {
    char s[len];
    int a;
}sort;

int cmp(const void *a,const void *b)
{
    char *sa = (*(sort*)a).s;
    char *sb = (*(sort*)b).s;
    int pa = (*(sort*)a).a;
    int pb = (*(sort*)b).a;
    if((pa < 0) && (pb < 0))
        return strcmp(sa,sb);
    else if(pa * pb <= 0 && pa != pb)
        return pa-pb;
    else{
        if(pa != pb)
            return pa-pb;
        else
            return strcmp(sa,sb);
    }
}

char h[len];

int main()
{
    // freopen("C:\\Users\\HP\\CLionProjects\\ecnuoj\\test","r",stdin);
    sort *ch = calloc(100,sizeof*ch);
    int cnt = 0;
    while((scanf("%s",h) != EOF))
    {
        int sig = 0;
        ch[cnt].a = -1;
        strcpy(ch[cnt].s,h);
        int index = 0,sum = 0;
        for(int i = 0;i < strlen(h);i++)
        {
            if((h[i] >= '0') && (h[i] <= '9'))
            {
                sig = 1;
                index = i;
                break;
            }
        }
        for(int i = index;i < len;i++)
        {
            if(isdigit(h[i]))
                sum = sum*10 + (h[i]-'0');
            else
                break;
        }
        if(sig)
            ch[cnt].a = sum;
        cnt++;
    }
    qsort(ch,cnt,sizeof(ch[0]),cmp);
    for(int i = 0;i < cnt;i++)
        printf("%s ",ch[i].s);

    return 0;
}