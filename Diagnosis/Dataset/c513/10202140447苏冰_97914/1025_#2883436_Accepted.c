#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct SS
{
    char c[25];
    int cnt;
}stu;
int a[100];
int cmp(const void* _a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    if((a->cnt)!=(b->cnt)) return ((b->cnt)-(a->cnt));
    else return (strcmp(a->c,b->c));
}
int solve(char s[])
{
    int n=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(a[s[i]]==0)
        {
            a[s[i]]=1;
            n++;
        }
    }
    memset(a,0,sizeof(a));
    return n;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    stu s[110];
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%s",s[j].c);
            s[j].cnt=solve(s[j].c);
        }
        qsort(s,n,sizeof(stu),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            printf("%s\n",s[j].c);
        }
    }
    return 0;
}

