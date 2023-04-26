#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct STU
{
    unsigned char name[70];
    int store;
    char day[20];
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
    int n;//n表示后面文件信息的行数
    scanf("%d\n",&n);
    stu s[120];
    char a[15];//存储命令
    while(n!=0)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%s",s[i].day);
            scanf("%s",s[i].time);
            scanf("%d",&s[i].store);
            scanf("%s",s[i].name);
        }
        gets(a);
        if(a[6]=='N')
        {
            qsort(s,n,sizeof(s[0]),cmp_NAME);
        }
        else if(a[6]=='S')
        {
            qsort(s,n,sizeof(s[0]),cmp_SIZE);
        }
        else if(a[6]=='T')
        {
            qsort(s,n,sizeof(s[0]),cmp_TIME);
        }
        for(int i = 0; i < n; i++)
        {
            printf("%s %s %16d %s\n",s[i].day,s[i].time,s[i].store,s[i].name);
        }
        scanf("%d\n",&n);
    }
    return 0;
}
