#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char date[11];
    char time[6];
    int size;
    char name[64];
}File;

int cmpNAME(const void* a,const void* b)
{
    File p=*((File*)a);
    File q=*((File*)b);
    return strcmp(p.name,q.name);
}
int cmpSIZE(const void* a,const void* b)
{
    File p=*((File*)a);
    File q=*((File*)b);
    int r=p.size-q.size;
    if(r) return r;
    else return strcmp(p.name,q.name);
    return strcmp(p.name,q.name);
}
int cmpTIME(const void* a,const void* b)
{
    File p=*((File*)a);
    File q=*((File*)b);
    if(strcmp(p.date,q.date)==0)
    {
        if(strcmp(p.time,q.time)==0) return strcmp(p.name,q.name);
        else return strcmp(p.time,q.time);
    }
    else return strcmp(p.date,q.date);
}
int main()
{
    int n,x=0;
    File file[100];
    char list[5],com[6];
    while((scanf("%d",&n)!=EOF)&&(n!=0))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s %s %d %s",file[i].date,file[i].time,&file[i].size,file[i].name);
        }
        scanf("%s %s",list,com);
        if(strcmp(com,"/NAME")==0) qsort(file,n,sizeof(file[0]),cmpNAME);
        if(strcmp(com,"/TIME")==0) qsort(file,n,sizeof(file[0]),cmpTIME);
        if(strcmp(com,"/SIZE")==0) qsort(file,n,sizeof(file[0]),cmpSIZE);
        if(x!=0) printf("\n");
        for(int i=0;i<n;i++)
        {
            printf("%s %s %16d %s\n",file[i].date,file[i].time,file[i].size,file[i].name);
        }
        x=x+1;
    }
    return 0;
}
