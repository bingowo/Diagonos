#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 2000001

int find(char *s)
{
    for(int i = 0;i < strlen(s);i++)
    {
        if(s[i] == '@')
            return i;
    }
    return 0;
}

char S[N];

typedef struct {
    char *s;
}node;

int cmp(const void *a,const void *b)
{
    char *pa = (*(node *)a).s;
    char *pb = (*(node *)b).s;
    int a1 = find(pa);
    int b1 = find(pb);
    int res = strcmp(pa+a1+1,pb+b1+1);
    if(res == 0)
        return -strcmp(pa,pb);
    else
        return res;
}

int main()
{
    int n;scanf("%d",&n);
    node ch[n];
    unsigned len = 0;
    for(int i = 0;i < n;i++)
    {
        scanf("%s",S+len);
        ch[i].s = S+len;
        len += strlen(S+len)+1;
    }
    qsort(ch,n,sizeof*ch,cmp);
    for(int i = 0;i < n;i++)
    {
        printf("%s\n",ch[i].s);
    }
    return 0;
}