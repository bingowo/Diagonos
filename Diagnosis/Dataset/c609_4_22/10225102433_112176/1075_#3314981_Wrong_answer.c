#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char c;
    int n;
    int place;
}node;

int cmp(const void *a,const void *b)
{
    if((*(node*)b).n != (*(node*)a).n)
        return (*(node*)b).n - (*(node*)a).n;
    else return (*(node*)a).place - (*(node*)b).place;
}

int main()
{
    char s[101] = {0};
    printf("\n");
    while((scanf("%s",s)) != EOF)
    {
        int cnt = 0;
        int len = strlen(s);
        node *ch = (node*)malloc(sizeof*ch*len);
        for(int i = 0;i < len;i++)
        {
            if(i == 0)
            {
                ch[i].place = i;
                ch[i].c = s[i];
                ch[i].n = 0;
            }
            else
            {
                ch[i].place = i;
                ch[i].c = s[i];
                if(s[i] > s[i-1]) ch[i].n = ++cnt;
                else ch[i].n = --cnt;
            }
        }
        qsort(ch,len,sizeof(ch[0]),cmp);
        printf("\n");
        for(int i = 0;i < len;i++)
        {
            int j;
            int res = ch[i].n;
            for(j = i;j < len;j++)
            {
                if(ch[j].n != res) break;
            }
            j--;
            int l = ch[j].place;
            char *t = (char*)malloc(sizeof(char)*(l+2));
            memset(t,' ',sizeof(char)*(l+1));
            for(int u = i;u <= j;u++)
            {
                t[ch[u].place] = ch[u].c;
            }
            t[l+1] = '\0';
            printf("%s\n",t);
            free(t);
            i = j;
        }
        free(ch);
        memset(s,'\0',sizeof(s));
    }
    return 0;
}