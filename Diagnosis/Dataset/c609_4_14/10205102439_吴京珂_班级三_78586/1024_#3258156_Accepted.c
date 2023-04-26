#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct NODE
{
    char name[64];
    int size;
    char date[11];//日期
    char time[6];
} node;

int cmpname(const void* a,const void* b)
{
    node p1=*(node*)a;
    node p2=*(node*)b;
    return strcmp(p1.name,p2.name);
}

int cmpsize(const void* a,const void* b)
{
    node p1=*(node*)a;
    node p2=*(node*)b;
    if(p1.size==p2.size) return strcmp(p1.name,p2.name);
    else return p1.size-p2.size;
}

int cmptime(const void* a,const void* b)
{
    node p1=*(node*)a;
    node p2=*(node*)b;
    if(strcmp(p1.date,p2.date)==0)
    {
        if(strcmp(p1.time,p2.time)==0)
            return strcmp(p1.name,p2.name);
        return strcmp(p1.time,p2.time);
    }
    else return strcmp(p1.date,p2.date);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        char list[5],field[6];
        node s[100];

        for(int i=0; i<n; i++)
        {
            scanf("%s%s%d%s",s[i].date,s[i].time,&s[i].size,s[i].name);
        }
        scanf("%s %s",list,field);

        if(field[1]=='N') qsort(s,n,sizeof(s[0]),cmpname);
        else if(field[1]=='S') qsort(s,n,sizeof(s[0]),cmpsize);
        else qsort(s,n,sizeof(s[0]),cmptime);

        for(int i=0; i<n; i++)
        {
            printf("%s %s %16d %s\n",s[i].date,s[i].time,s[i].size,s[i].name);
        }
        printf("\n");
    }

    return 0;
}
