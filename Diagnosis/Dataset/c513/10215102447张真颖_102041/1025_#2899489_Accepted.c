#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(char s[])
{
    int arr[91],count=0;
    for(int i=0;i<91;i++)
        arr[i]=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(arr[s[i]]==0)
        {
            arr[s[i]]=1;
            count+=1;
        }
    }
    return count;
}

int cmp(const void* a ,const void* b)
{
    char *pa=*(char**)a,*pb=*(char**)b;
    int counta=0,countb=0;
    counta=count(pa);
    countb=count(pb);
    if(counta!=countb) return countb-counta;
    else return strcmp(pa,pb);
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n=0,len=0;
        scanf("%d",&n);
        char**s;
        s=(char**)malloc(n*sizeof(char*));
        char t[21],*p;
        for(int i=0;i<n;i++)
        {
            scanf("%s",t);
            len=strlen(t);
            p=(char*)malloc(len+1);
            strcpy(p,t);
            *(s+i)=p;
        }
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<n;i++)
            printf("%s\n",*(s+i)),free(*(s+i));
        free(s);
    }
    return 0;
}
