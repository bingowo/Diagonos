#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct file{
    char date[11];
    char time[6];
    int size;
    char name[64];
}file;
int cmpname(const void*p1,const void*p2)
{
    file a=*(file*)p1;
    file b=*(file*)p2;
    return strcmp(a.name,b.name);
}
int cmpsize(const void*p1,const void*p2)
{
    file a=*(file*)p1;
    file b=*(file*)p2;
    if(a.size==b.size)return strcmp(a.name,b.name);;
    return a.size-b.size;//up
}
int cmptime(const void*p1,const void*p2)
{
    file a=*(file*)p1;
    file b=*(file*)p2;
    if(strcmp(a.date,b.date)==0){
        if(strcmp(a.time,b.time)==0)
        return strcmp(a.name,b.name);
        return strcmp(a.time,b.time);
    }
    return strcmp(a.date,b.date);
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        char list[5],cmd[6];
        file f[100];
        for(int i=0;i<n;i++)
        scanf("%s%s%d%s",f[i].date,f[i].time,&f[i].size,f[i].name);
        scanf("%s%s",list,cmd);
        if(cmd[1]=='N')qsort(f,n,sizeof(file),cmpname);
        else if(cmd[1]=='S')qsort(f,n,sizeof(file),cmpsize);
        else qsort(f,n,sizeof(file),cmptime);
        
        for(int i=0;i<n;i++)
        printf("%s %s %16d %s\n",f[i].date,f[i].time,f[i].size,f[i].name);
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}