#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[30];
    int count;
} STR;

int cnt(char* s)
{
    int i,j=1;
    char s1[30]={0};
    s1[0]=s[0];
    for (i=1;i<strlen(s);i++)
    {
        if (s[i]!=s[i-1] && strchr(s1,s[i])==NULL)
        {
            s1[j++]=s[i];

        }
    }
    return j;
}

int cmp(const void *a,const void *b)
{
    STR* pa=(STR*)a; STR* pb=(STR*)b;
    if (pa->count>pb->count) return -1;
    if (pa->count<pb->count) return 1;
    if (pa->count==pb->count)
    {
        return strcmp(pa->s,pb->s)<0?-1:1;
    }
}

int main()
{
    int T,n,j;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&n);
        STR* arr=(STR*)malloc(n*sizeof(STR));
        for (j=0;j<n;j++)
        {
            scanf("%s",arr[j].s);
            arr[j].count=cnt(arr[j].s);
        }
        qsort(arr,n,sizeof(STR),cmp);

        for (j=0;j<n;j++)
            printf("%s\n",arr[j].s);
        free(arr);
    }
    return 0;
}
