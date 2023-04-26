#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FILE
{
    unsigned char name[64];
    int size;
    char day[11];
    char time[10];
}file;

int cmp_NAME(const void* _a,const void*_b)
{
    file* a=(file*)_a;
    file* b=(file*)_b;
    return (strcmp(a->name,b->name));

}

int cmp_SIZE(const void* _a,const void*_b)
{
    file* a=(file*)_a;
    file* b=(file*)_b;
    if(a->size!=b->size)
        return ((a->size)>(b->size)?1:-1);
    else return (strcmp(a->name,b->name));
}

int cmp_TIME(const void* _a,const void*_b)
{
    file* a = (file*)_a;
    file* b = (file*)_b;
    if(strcmp(a->day,b->day)!=0)
    {
        return (strcmp(a->day,b->day));
    }
    else if(strcmp(a->time,b->time)!=0)
    {
        return (strcmp(a->time,b->time));
    }
    else return (strcmp(a->name,b->name));
}

int main()
{
    int n,flag=1;
    file s[120];
    scanf("%d",&n);
    char a[15];
    while(n!=0)
    {
        if(flag!=1)   printf("\n");
        for(int i=0;i<n;i++)
        {
            scanf("%s %s %d %s",s[i].day,s[i].time,&s[i].size,s[i].name);
        }
        gets(a);
        gets(a);
        if(a[6]=='N') qsort(s,n,sizeof(file),cmp_NAME);
        else if(a[6]=='S') qsort(s,n,sizeof(file),cmp_SIZE);
        else if(a[6]=='T') qsort(s,n,sizeof(file),cmp_TIME);
        for(int i=0;i<n;i++)
        {
            printf("%s %s %16d %s\n",s[i].day,s[i].time,s[i].size,s[i].name);
        }
        flag=0;
        scanf("%d",&n);
    }
    return 0;
}
