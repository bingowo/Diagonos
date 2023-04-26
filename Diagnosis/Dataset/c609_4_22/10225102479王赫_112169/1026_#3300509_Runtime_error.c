#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct
{
    int num;
    char s[21];
}str;
int cnt(char s[])
{
    int cnt=0;
    int len=strlen(s);
    int n[24];
    int i=0;
    for(i=0;i<len;i++)
    {
        int k=s[i]-'65';
        n[k]+=1;
    }
    for(int j=0;j<len;j++)
    {
        if(n[i]) cnt++;
    }
    return cnt;
}
int cmp(const void* x,const void* y)
{
    str* a=(str*)x;
    str* b=(str*)y;
    int cnt1=cnt(a->s),cnt2=cnt(b->s);
    if(cnt1!=cnt2) return cnt2-cnt1;
    else return strcmp(a->s,b->s);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        str m[n+1];
        m->num=0;
        int j=0;
        for(j=0;j<n;j++)
        {
            scanf("%s",m->s[(m->num)++]);
        }
        qsort(m->s,n,sizeof(m->s[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
        {
            printf("%s\n",m->s[j]);
        }
    }
    return 0;
}
