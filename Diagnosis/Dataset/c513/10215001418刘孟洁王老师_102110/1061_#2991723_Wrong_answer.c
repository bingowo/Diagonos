#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{char s[17];int val;}num;

int cmp(const void*a,const void*b)
{
    num c = *(num*)a;
    num d = *(num*)b;
    if(c.val > d.val)return 1;
    else if(c.val < d.val)return -1;
    else if(strcmp(c.s,d.s) < 0)return -1;
    else return 1;
}

int main()
{
    int cas,i,j,p[128];
    num t[10007];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)scanf("%s",t[i].s);
    for(i = 0; i < cas; i++)
    {
        t[i].val = 0;
        for(j = 0; j < 128; j++)p[j] = -1;
        int len = strlen(t[i].s);
        p[t[i].s[0]] = 1;
        int digit = 0;
        for(j = 1; j < len; j++)
        {
            if(p[t[i].s[j]] == -1)
            {
                p[t[i].s[j]] = digit;
                digit = digit == 0?2:digit+1;
            }
        }
        digit = digit>2?digit:2;
        for(j = 0; j < len; j++)t[i].val = t[i].val*digit + p[t[i].s[j]];
    }
    qsort(t,cas,sizeof(t[0]),cmp);
    for(i = 0; i < cas; i++)printf("%s\n",t[i].s);
    return 0;
}