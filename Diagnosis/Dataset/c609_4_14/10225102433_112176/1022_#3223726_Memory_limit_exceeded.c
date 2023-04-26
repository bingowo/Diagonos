#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000010

int find(char *s)
{
    for(int i = 0;i < strlen(s);i++)
    {
        if(s[i] == '@')
            return i;
    }
    return 0;
}

typedef struct {
    char S[N];
    char s1[N];
    char s2[N];
}node;

void copychar(const char *s,int b,int e,char *r)
{
    int cnt = 0;
    for(int i = b;i <= e;i++)
    {
        r[cnt++] = s[i];
    }
    r[cnt] = '\0';
}

int cmp(const void *a,const void *b)
{
    node *pa = (node *)a;
    node *pb = (node *)b;
    int name = strcmp(pa->s2,pb->s2);
    if(name != 0)
        return name;
    else
    {
        int place = strcmp(pa->s1,pb->s1);
        return -place;
    }
}

int main()
{
    int n;scanf("%d",&n);
    node *ch = malloc(n*sizeof*ch);
    for(int i = 0;i < n;i++)
    {
        memset(ch[i].S,'\0',sizeof(ch[i].S));
        scanf("%s",ch[i].S);
        int sig = find(ch[i].S);
        copychar(ch[i].S,0,sig-1,ch[i].s1);
        copychar(ch[i].S,sig+1, strlen(ch[i].S)-1,ch[i].s2);
    }
    qsort(ch,n,sizeof*ch,cmp);
    for(int i = 0;i < n;i++)
    {
        printf("%s\n",ch[i].S);
    }
    free(ch);
    return 0;
}