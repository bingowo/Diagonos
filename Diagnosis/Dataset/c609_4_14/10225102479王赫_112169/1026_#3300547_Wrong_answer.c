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
    int n[26]={0};
    int i=0;
    for(i=0;i<len;i++)
    {
        int k=s[i]-'A';
        n[k]+=1;
    }
    for(int j=0;j<26;j++)
    {
        if(n[i]) cnt++;
    }
    return cnt;
}
int cmp(const void* x,const void* y)
{
    str* a=(str*)x;
    str* b=(str*)y;
    if(a->num!=b->num) return b->num-a->num;
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
        str* m=(str*)malloc(sizeof(str)*n);
        int j=0;
        for(j=0;j<n;j++)
        {
            scanf("%s",m[j].s);
            m[j].num=cnt(m[i].s);
        }
        qsort(m,n,sizeof(m[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<n;k++)
        {
            printf("%s\n",m[k].s);
        }
        free(m);
    }
    return 0;
}
