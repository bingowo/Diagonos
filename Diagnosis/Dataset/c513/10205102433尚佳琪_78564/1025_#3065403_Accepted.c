#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[50];
    int cnt;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.cnt!=s2.cnt)
        return s2.cnt-s1.cnt;
    else
    {
        return strcmp(s1.s,s2.s);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        node a[n];
        for(int j=0;j<n;j++)
        {
            a[j].cnt=0;
            scanf("%s",a[j].s);
            int len=strlen(a[j].s);
            int p[26]={0};
            for(int k=0;k<len;k++)
                p[a[j].s[k]-'A']=1;
            for(int i=0;i<26;i++)
            {
                if(p[i]>0)a[j].cnt++;
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<n;i++)
            printf("%s\n",a[i].s);
    }
}
