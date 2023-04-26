#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    char S[1000010];
}node;

int cmp(const void *a,const void *b)
{
    char *pa = (char *)a;
    char *pb = (char *)b;
    int a1 = find(pa);
    int b1 = find(pb);
    int res = strcmp(pa+a1+1,pb+b1+1) == 0;
    if(res == 0)
        return -strcmp(pa,pb);
    else
        return res;
}

int main()
{
    int n;scanf("%d",&n);
    node ch[n];
    for(int i = 0;i < n;i++)
    {
        memset(ch[i].S,'\0',sizeof(ch[i].S));
        scanf("%s",ch[i].S);
    }
    qsort(ch,n,sizeof*ch,cmp);
    for(int i = 0;i < n;i++)
    {
        printf("%s\n",ch[i].S);
    }
    return 0;
}