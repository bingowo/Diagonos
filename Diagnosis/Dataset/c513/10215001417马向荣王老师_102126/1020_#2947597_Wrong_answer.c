#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char date[11];
    char name[70];
    int size;
    char time[11];
}File;
int cmptime(const void *a,const void *b)
{
    File *p1=(File*)a;
    File *p2=(File*)b;
    if(strcmp(p1->date,p2->date)==0)
    {
        if(strcmp(p1->time,p2->time)==0)
            return strcmp(p1->name,p2->name);
        return strcmp(p1->time,p2->time);
    }
    return strcmp(p1->date, p2->date);
}
int cmpname(const void *a,const void *b)
{
    File *p1=(File*)a;
    File *p2=(File*)b;
    return strcmp(p1->name,p2->name);
}
int cmpsize(const void *a,const void *b)
{
    File *p1=(File*)a;
    File *p2=(File*)b;
    if(p1->size==p2->size) 
        return strcmp(p1->name,p2->name);
    return p1->size-p2->size;
}
int main()
{
    int n=0;
    scanf("%d\n",&n);
    char list[5],command[6];
    while(n)
    {
        File file[100];
        int i=0;
        for(i=0;i<n;i++)
        {
            scanf("%s %s %d %s",file[i].date,file[i].time,&file[i].size,file[i].name);
        }
        scanf("%s %s",list,command);
        if(strcmp(command,"/NAME")==0)
        {
            qsort(file,n,sizeof(file[0]),cmpname);
        }
        else if(strcmp(command,"/SIZE")==0)
        {
            qsort(file,n,sizeof(file[0]),cmpsize);
        }
        else qsort(file,n,sizeof(file[0]),cmptime);
        for(i=0;i<n;i++)
        {
            printf("%s %s %16d %s",file[i].date,file[i].time, file[i].size,file[i].name);
        }
        printf("\n");
        if(scanf("%d",&n)==0) break;
    }
    return 0;
}