#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt(const char* str)
{
    int table[26]={0};
    char *p=str;
    int count=0;
    while(*p)
    {
        if(table[(*p)-'A']==0)
        {
            count++;
            table[(*p)-'A']=1;
        }
        p++;
    }
    //printf("%d\n",count);
    return count;
}

int cmp(const void *_str1,const void *_str2)
{
    char *str1=*(char **)_str1;
    char *str2=*(char **)_str2;
    int a=cnt(str1);
    int b=cnt(str2);
    if(a!=b)
        return a>b?-1:1;
    else
        return strcmp(str1,str2);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int Case=0;Case<T;Case++)
    {
        int n;
        scanf("%d",&n);
        char **str=(char**)malloc(n*sizeof(char*));
        char digit[50]={0};
        for(int i=0;i<n;i++)
        {
            scanf("%s",digit);
            str[i]=(char *)malloc((strlen(digit)+1)*sizeof(char));
            strncpy(str[i],digit,strlen(digit)+1);
        }
        qsort(str,n,sizeof(char*),cmp);
        printf("case #%d:\n",Case);
        for(int i=0;i<n;i++)
        {
            printf("%s\n",str[i]);
            free(str[i]);
        }
        free(str);
    }
    return 0;
}
