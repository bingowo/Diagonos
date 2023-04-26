#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char day[11];
    char time[10];
    unsigned long long size;
    char name[66];
}File;

int cmp1(const void *a,const void *b)
{
    File *x=(File *)a;
    File *y=(File *)b;
    if(strcmp(x->day,y->day)!=0)
    {
        return (strcmp(x->day,y->day));
    }
    else if(strcmp(x->time,y->time)!=0)
        {
            return (strcmp(x->time,y->time));
        }
        else
        return (strcmp(x->name,y->name));
}

int cmp2(const void *a,const void *b)
{
    File *x=(File *)a;
    File *y=(File *)b;
    if(x->size!=y->size)
    {return ((x->size)>(y->size)?1:-1);}
    else
        return (strcmp(x->name,y->name));
}

int cmp3(const void *a,const void *b)
{
    File *x=(File *)a;
    File *y=(File *)b;
    return (strcmp(x->name,y->name));
}

int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        File m[n];
    for(i=0;i<n;i++)
    {
        scanf("%s %s %d %s",m[i].day,m[i].time,&m[i].size,m[i].name);

    }
    char a[15];
    gets(a);
    gets(a);
    if(strcmp(a,"LIST /NAME")==0)
    {
        qsort(m,n,sizeof(File),cmp3);
    }
    else if(strcmp(a,"LIST /SIZE")==0)
    {
         qsort(m,n,sizeof(File),cmp2);
         printf("helloworld");
    }
    else if(strcmp(a,"LIST /TIME")==0)
    {
        printf("next");
         qsort(m,n,sizeof(File),cmp1);
    }

    for(i=0;i<n;i++)
    {
         printf("%s %s %-16llu %s\n",m[i].day,m[i].time,m[i].size,m[i].name);
    }
    printf("\n");
        
    }
    
    return 0;
}