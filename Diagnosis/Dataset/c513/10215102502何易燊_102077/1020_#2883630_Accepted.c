#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {char date[50]; char time[50]; int size; char name[50];} file;

int cmp0(const void* a,const void* b)
{
    file* a_ = (file*)a;
    file* b_ = (file*)b;
    if (strcmp(a_->date,b_->date)) return strcmp(a_->date,b_->date);
    if (strcmp(a_->time,b_->time)) return strcmp(a_->time,b_->time);
    return strcmp(a_->name,b_->name);
}

int cmp1(const void* a,const void* b)
{
    file* a_ = (file*)a;
    file* b_ = (file*)b;
    return strcmp(a_->name,b_->name);
}

int cmp2(const void* a,const void* b)
{
    file* a_ = (file*)a;
    file* b_ = (file*)b;
    if (a_->size!=b_->size) return (a_->size-b_->size);
    return strcmp(a_->name,b_->name);
}

main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (!n) break;
        file a[102];
        for (int i=0;i<n;i++)
        {
            scanf("%s %s %d %s",a[i].date,a[i].time,&a[i].size,a[i].name);
        }
        char s[15],t[15];
        scanf("%s %s",s,t);
        if (!strcmp(t,"/TIME")) qsort(a,n,sizeof(a[0]),cmp0);
        else if (!strcmp(t,"/NAME")) qsort(a,n,sizeof(a[0]),cmp1);
        else qsort(a,n,sizeof(a[0]),cmp2);
        for (int i=0;i<n;i++)
            printf("%s %s %16d %s\n",a[i].date,a[i].time,a[i].size,a[i].name);
        printf("\n");
    }
    return 0;
}