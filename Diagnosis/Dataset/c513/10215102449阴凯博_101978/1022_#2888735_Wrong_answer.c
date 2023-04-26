#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char user[100001];
    char host[100001];
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
    if (strcmp(pa->host,pb->host)<0) return -1;
    if (strcmp(pa->host,pb->host)>0) return 1;
    if (strcmp(pa->host,pb->host)==0)
    {
        return strcmp(pa->user,pb->user)<0?1:-1;
    }
}

int main()
{
    int T,n,j;
    scanf("%d",&T);
    STR* arr=(STR*)malloc(T*sizeof(STR));
    for (int i=0;i<T;i++)
    {
        
        scanf("%s@%s",arr[i].user,arr[i].host);
        
    }
    qsort(arr,T,sizeof(STR),cmp);
    for (j=0;j<T;j++)
        printf("%s@%s\n",arr[j].user,arr[j].host);
    free(arr);
    return 0;
}
