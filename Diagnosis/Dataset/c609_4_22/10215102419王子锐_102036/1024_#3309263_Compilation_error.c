#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct STU
{
    unsigned char c[70];
    int store;
    char day[20];
    char time[10];
}stu;
int cmp_name(const void* _a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    return (strcmp(a->c,b->c));

}
int cmp_size(const void* _a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    if(a->store!=b->store) return ((a->store)>(b->store)?1:-1);
    else return (strcmp(a->c,b->c));
}
int cmp_time(const void* _a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    if(strcmp(a->day,b->day)!=0)
    {
        return (strcmp(a->day,b->day));
    }
    else if(strcmp(a->time,b->time)!=0)
    {
        return (strcmp(a->time,b->time));
    }
    else
    {
        return (strcmp(a->c,b->c))
    }
}
int main()
{
    int n;
    stu s[120];
    while((scanf("%d", &n)) != EOF && n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s %s %d %s",s[i].day,s[i].time,&s[i].store,s[i].c);
        }
		char a[15];
        gets(a);
        gets(a);
        if(strstr(a,"LIST /NAME") != NULL) qsort(s,n,sizeof(stu),cmp_name);
        else if(strstr(a,"LIST /SIZE") != NULL) qsort(s,n,sizeof(stu),cmp_size);
        else if(strstr(a,"LIST /TIME") != NULL) qsort(s,n,sizeof(stu),cmp_time);
        for(int i=0;i<n;i++)
        {
            printf("%s %s %16d %s\n",s[i].day,s[i].time,s[i].store,s[i].c);
        }
        printf("\n");
    }
    return 0;
}