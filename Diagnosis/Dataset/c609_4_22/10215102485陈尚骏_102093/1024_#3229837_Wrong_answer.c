#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    char data[10];
    char time[6];
    char name[7];
    int size;
}File;


int cmptime(const void*a,const void*b)
{
    File*a1=(File*)a;
    File*b1=(File*)b;
    if(!strcmp(a1->data,b1->data))
    {
        if(!strcmp(a1->time,b1->time))
        {
            return strcmp(a1->name,b1->name);
        }
        else return strcmp(a1->time,b1->time);
    }
    else return strcmp(a1->data,b1->data);
}

int cmpname(const void*a,const void*b)
{
    File*a1=(File*)a;
    File*b1=(File*)b;
    return strcmp(a1->name,b1->name);
}

int cmpsize(const void*a,const void*b)
{
    File*a1=(File*)a;
    File*b1=(File*)b;
    if(a1->size==b1->size) return strcmp(a1->name,b1->name);
    else return a1->size-b1->size;
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[6],List[5];
    while(1)
    {
        File fl[101];
        int i=0;
        for(;i<n;++i)
        {
            scanf("%s%s%d%s",fl[i].data,fl[i].time,&fl[i].size,fl[i].name);
        }
        scanf("%s%s",List,s);
        if(!strcmp(s,"/NAME")) qsort(fl,n,sizeof(fl[0]),cmpname);
        else if(!strcmp(s,"/SIZE")) qsort(fl,n,sizeof(fl[0]),cmpsize);
        else qsort(fl,n,sizeof(fl[0]),cmptime);
        for(i=0;i<n;++i)
        {
            printf("%s %s %16d %s\n",fl[i].data,fl[i].time,fl[i].size,fl[i].name);
        }
        printf("\n");
        if(scanf("%d",&n)==EOF) break;
    }
    return 0;
}
