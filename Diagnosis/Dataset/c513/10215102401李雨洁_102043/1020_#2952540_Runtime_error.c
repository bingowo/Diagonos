#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct STU
{
    unsigned char name[64];
    int store;
    char day[11];
    char time[10];
}stu;

int cmp_NAME(const void* _a,const void*_b)
{
    stu* a = (stu*)_a;
    stu* b = (stu*)_b;
    return (strcmp(a->name,b->name));

}

int cmp_SIZE(const void* _a,const void*_b)
{
    stu* a = (stu*)_a;
    stu* b = (stu*)_b;
    if(a->store != b->store)
        return ((a->store) > (b->store) ? 1 : -1);
    else return (strcmp(a->name,b->name));
}

int cmp_TIME(const void* _a,const void*_b)
{
    stu* a = (stu*)_a;
    stu* b = (stu*)_b;
    if(strcmp(a->day,b->day) != 0)
    {
        return (strcmp(a->day,b->day));
    }
    else if(strcmp(a->time,b->time)!=0)
    {
        return (strcmp(a->time,b->time));
    }
    else
    {
        return (strcmp(a->name,b->name));
    }
}

int main()
{
    int n;
    stu s[120];
    scanf("%d\n",&n);
    char a[15];
    int i = 0, j = 0;
    while(n)
    {
        for(; i < n; i++)
        {
            scanf("%s",s[i].day);
            scanf("%s",s[i].time);
            scanf("%d",&s[i].store);
            scanf("%s",s[i].name);
        }
        gets(a);
        if(a[6] == 'N') qsort(s,n,sizeof(stu),cmp_NAME);
        else if(a[6] == 'S') qsort(s,n,sizeof(stu),cmp_SIZE);
        else if(a[6] == 'T') qsort(s,n,sizeof(stu),cmp_TIME);
        for(; j < n; j++)
        {
            printf("%s %s %16d %s\n",s[j].day,s[j].time,s[j].store,s[j].name);
        }
        scanf("%d\n",&n);
    }
    return 0;
}