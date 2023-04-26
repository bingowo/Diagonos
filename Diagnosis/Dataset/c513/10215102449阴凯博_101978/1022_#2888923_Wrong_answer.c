#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char user[1000];
    char host[1000];
} STR;

typedef struct
{
    char user[10];
    char host[10];
} STR1;


int mgetline(char s[],int lim)
{
    int c,i;
    i=0;
    while ((c=getchar())!=EOF && c!='\n' && i<lim-1 && c!='@')
        s[i++]=c;
    if (c==EOF && i==0)
        return -1;
    s[i]='\0';
    return i;
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
    int a,b;
    scanf("%d",&T);
    getchar();

    if (T>100000)
    {
        STR1* arr=(STR1*)malloc(T*sizeof(STR));
        for (int i=0;i<T;i++)
        {
            a=mgetline(arr[i].user,10);
            b=mgetline(arr[i].host,10);
        }
        qsort(arr,T,sizeof(STR1),cmp);
        for (j=0;j<T;j++)
            printf("%s@%s\n",arr[j].user,arr[j].host);
        free(arr);
    }
    else
    {
        STR* arr=(STR*)malloc(T*sizeof(STR));
        for (int i=0;i<T;i++)
        {
            a=mgetline(arr[i].user,1000);
            b=mgetline(arr[i].host,1000);
        }
        qsort(arr,T,sizeof(STR),cmp);
        for (j=0;j<T;j++)
            printf("%s@%s\n",arr[j].user,arr[j].host);
        free(arr);
    }


    return 0;
}
