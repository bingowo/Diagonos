#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char s[50];
    int num;
}NODE;
int cl(NODE a)
{
    int q[128]={0};
    int len=strlen(a.s);
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        if(q[a.s[i]]==0)
        {
            q[a.s[i]]=1;
            cnt++;
        }
    }
    return cnt;
}
int cmp(const void *a,const void *b)
{
    NODE s1=*(NODE *)a;
    NODE s2=*(NODE *)b;
    int len1;len1=cl(s1);
    int len2;len2=cl(s2);
    if(len1!=len2)
        return len2-len1;
    else
        return strcmp(s1.s,s2.s);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        NODE ans[n];
        for(int j=0;j<n;j++)
            scanf("%s",ans[j].s);
        qsort(ans,n,sizeof(ans[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<n;i++)
            printf("%s\n",ans[i].s);
    }
    return 0;
}
