#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char date[11];
    char time[6];
    char size[10];
    char name[64];
}File;
int comparN(const void *p1,const void *p2);
int comparS(const void *p1,const void *p2);
int comparT(const void *p1,const void *p2);
void myPrint(File *file);
int main()
{
    int n,i;
    char command[10];
    File *file;
    do
    {
        scanf("%d",&n);
        file=(File*)malloc(n*sizeof(File));
        for(i=0;i<n;i++)
        {
            scanf("%s",file[i].date);
            scanf("%s",file[i].time);
            scanf("%s",file[i].size);
            scanf("%s",file[i].name);
        }
        scanf("%s",command);
        scanf("%s",command);
        if(command[strlen(command)-4]=='N')
            qsort(file,n,sizeof(File),comparN);
        else if(command[strlen(command)-4]=='S')
            qsort(file,n,sizeof(File),comparS);
        else
            qsort(file,n,sizeof(File),comparT);

        for(i=0;i<n;i++)
        {
            myPrint(file+i);
        }
        printf("\n");
        free(file);
    }
    while(n!=0);
    return 0;
}

int comparN(const void *p1,const void *p2)
{
    int flag=0;
    File *a,*b;
    a=(File*)p1;
    b=(File*)p2;
    flag=strcmp(a->name,b->name);
    return flag;
}
int comparS(const void *p1,const void *p2)
{
    int flag=0;
    File *a,*b;
    a=(File*)p1;
    b=(File*)p2;
    if(strlen(a->size)<strlen(b->size))
        flag=-1;
    else if(strlen(a->size)>strlen(b->size))
        flag=1;
    else
    {
        if(a->size[strlen(a->size)-1]<b->size[strlen(b->size)-1])
            flag=-1;
        else if(a->size[strlen(a->size)-1]>b->size[strlen(b->size)-1])
            flag=1;
        else
            flag=comparN(a,b);
    }
    return flag;
}
int comparT(const void *p1,const void *p2)
{
    int flag=0;
    File *a,*b;
    a=(File*)p1;
    b=(File*)p2;
    flag=strcmp(a->date,b->date);
    if(flag<0||flag>0);
    else
    {
        flag=strcmp(a->time,b->time);
        if(flag<0||flag>0);
        else
            flag=comparN(a,b);
    }
    return flag;
}
void myPrint(File *file)
{
    printf("%s ",file->date);
    printf("%s ",file->time);
    printf("%16s ",file->size);
    printf("%s\n",file->name);
}
