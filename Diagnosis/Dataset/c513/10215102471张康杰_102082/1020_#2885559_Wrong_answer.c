#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int size;
    char time1[20];
    char time2[10];
    char name[64];
}File;
int cmp_TIME(const void*a,const void*b)
{
    File*st1,*st2;
    st1 = (File*)a,st2 = (File*)b;
    if(strcmp(st1->time1,st2->time1) != 0)
        return strcmp(st1->time1,st2->time1);
    else
        return strcmp(st1->time2,st2->time2);

}
int cmp_SIZE(const void*a,const void*b)
{
    File*st1,*st2;
    st1 = (File*)a,st2 = (File*)b;
    return st1->size - st2->size;

}
int cmp_NAME(const void*a,const void*b)
{
    File*st1,*st2;
    st1 = (File*)a,st2 = (File*)b;
    return strcmp(st1->name,st2->name);
}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        File file[n];
        for(int i = 0;i < n;i++)
        {
            scanf("%s %s %d %s",file[i].time1,file[i].time2,&file[i].size,file[i].name);
        }
        char mod[5];
        scanf("LIST /%s",mod);
        if(strcmp("NAME",mod) == 0)
        {
            qsort(file,n,sizeof(file[0]),cmp_NAME);
        }
        else if(strcmp("TIME",mod) == 0)
        {
            qsort(file,n,sizeof(file[0]),cmp_TIME);
        }
        else
            qsort(file,n,sizeof(file[0]),cmp_SIZE);
        for(int i = 0;i < n;i++)
        {
            printf("%s %s %-d %-16s\n",file[i].time1,file[i].time2,file[i].size,file[i].name);
        }
        putchar('\n');
    }
    return 0;
}
