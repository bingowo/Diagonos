#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char s[501];
}node;

int check(char c)
{
    if((c == '!') || (c == '.') || (c == ',') || (c == '?'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int cmp(const void *a,const void *b)
{
    node *pa = (node*)a;
    node *pb = (node*)b;
    return strcmp(pa->s,pb->s);
}

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        printf("case #%d:\n",i);
        node *ch = (node*)malloc(501*sizeof*ch);
        int cnt = 0;
        char t[501] = {0},c;
        int sig = 1;
        while(sig)
        {
            int sig2 = 1;
            scanf("%s%c",t,&c);
            if(c == '\n')
                sig = 0;
            unsigned len = strlen(t);
            for(int j = 0;j < len;j++)
            {
                if(check(t[j]))
                {
                    sig2 = 0;
                    if(j == len-1)
                    {
                        t[len-1] = '\0';
                        strcpy(ch[cnt++].s,t);
                    }
                    else
                    {
                        char res[50] = {0};
                        for(int h = j+1;h < len;h++)
                        {
                            res[h-j-1] = t[h];
                        }
                        t[j] = '\0';
                        strcpy(ch[cnt++].s,res);
                        strcpy(ch[cnt++].s,t);
                    }
                    break;
                }
            }
            if(sig2)
            {
                strcpy(ch[cnt++].s,t);
            }
            memset(t,'\0',sizeof(t));
        }
        qsort(ch,cnt,sizeof(ch[0]),cmp);
        printf("%s ",ch[0].s);
        for(int j = 1;j < cnt;j++)
        {
            if(strcmp(ch[j-1].s,ch[j].s) == 0)
                continue;
            else
                printf("%s ",ch[j].s);
        }
        printf("\n");
        free(ch);
    }
    return 0;
}