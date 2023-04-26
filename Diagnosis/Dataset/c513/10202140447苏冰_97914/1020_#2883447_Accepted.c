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
int cmp1(const void* _a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    return (strcmp(a->c,b->c));

}
int cmp2(const void* _a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    if(a->store!=b->store) return ((a->store)>(b->store)?1:-1);
    else return (strcmp(a->c,b->c));
}
int cmp3(const void* _a,const void*_b)
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
        return (strcmp(a->c,b->c));
    }
}
int main()
{
    int n,x=1;
    stu s[120];
    scanf("%d",&n);
    char a[15];
    while(n!=0)
    {
        if(x!=1)   printf("\n");
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i].day);
            scanf("%s",s[i].time);
            scanf("%d",&s[i].store);
            scanf("%s",s[i].c);
        }
        gets(a);
        gets(a);
        if(a[6]=='N') qsort(s,n,sizeof(stu),cmp1);
        else if(a[6]=='S') qsort(s,n,sizeof(stu),cmp2);
        else if(a[6]=='T') qsort(s,n,sizeof(stu),cmp3);
        for(int i=0;i<n;i++)
        {
            printf("%s %s %16d %s\n",s[i].day,s[i].time,s[i].store,s[i].c);
        }
        x=0;
        scanf("%d",&n);
    }
    return 0;
}

