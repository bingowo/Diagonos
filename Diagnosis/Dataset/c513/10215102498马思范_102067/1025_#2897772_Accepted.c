#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int diff;
    char c[30];
}word;

int gdiff(word w)
{
    int temp=0;
    int flag[26]={0};
    for(int k=0;w.c[k]!='\0';k++)
    {
        if(flag[w.c[k]-'A']==0)
            temp++;
        flag[w.c[k]-'A']++;
    }
    return temp;
}

int cmp(const void *a,const void *b)
{
    word x=*(word*)a;
    word y=*(word*)b;
    if(x.diff!=y.diff)
        return y.diff-x.diff;
    else
        return strcmp(x.c,y.c);
}

int main()
{
    int t;
    int n;
    word a[101];
    scanf("%d",&t);
    for(int m=0;m<t;m++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",&a[i].c);
            a[i].diff= gdiff(a[i]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",m);
        for(int r=0;r<n;r++)
            printf("%s\n",a[r].c);
    }
    return 0;
}