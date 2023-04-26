#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[31];
    int cnt;
}str;
int cmp(const void *a,const void *b)
{
    str p=*((str *)a);
    str q=*((str *)b);
    if(p.cnt!=q.cnt)
    return q.cnt-p.cnt;
    else return strcmp(p.s,q.s);
}
int count(char *s)
{
    int m[1000]={0};
    int c=strlen(s);
    while(*s)
    {
        if(m[*s]==1) c--;
        else{ m[*s]=1;}
        s++;
    }
    return c;
}
int main()
{
    int T,N;
    str l[1000];
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            scanf("%s",l[j].s);
            l[j].cnt=count(l[j].s);
        }
        qsort(l,N,sizeof(l[0]),cmp);
        printf("case #%d:\n",cas);
        for(int k=0;k<N;k++)
        {
            printf("%s\n",l[k].s);
        }
    }
    return 0;
}
