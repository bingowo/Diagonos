#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    char s[21];
    int m;
}node;

int num(char str[])
{
    int len=strlen(str);
    int a[27]={0};
    for(int i=0;i<len;i++)
    {
        a[str[i]-'A']++;
    }
    int count=0;
    for(int i=0;i<27;i++)
    {
        if(a[i]!=0) count++;
    }
    return count;
}

int cmp(const void *a,const void *b)
{
    node p1,p2;
    p1=*((node *)a);
    p2=*((node *)b);
    if(p1.m!=p2.m) return p2.m-p1.m;
    else return strcmp(p1.s,p2.s);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n;
        scanf("%d",&n);
        node p[n];
        int j;
        for(j=0;j<n;j++)
        {
            scanf("%s",p[j].s);
            p[j].m=num(p[j].s);
        }

        qsort(p,n,sizeof(p[0]),cmp);

        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
        {
            printf("%s\n",p[j].s);
        }

    }
    return 0;
}
