#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file
{
    char time[6];
    char day[11];
    int store;
    char name[70];
};

int cmp1(const void* a,const void* b)
{
    struct file* c=(struct file*)a;
    struct file* d=(struct file*)b;
    return (strcmp(c->name,d->name));
}

int cmp2(const void* a,const void* b)
{
    struct file* c=(struct file*)a;
    struct file* d=(struct file*)b;
    return c->store-d->store;
}

int cmp3(const void* a,const void* b)
{
    struct file* c=(struct file*)a;
    struct file* d=(struct file*)b;
    if(strcmp(c->day,d->day)!=0)
        return strcmp(c->day,d->day);
    else
        return strcmp(c->time,d->time);
}

int main()
{
    int n,i;
    struct file *f;
    char s[10];
    do
    {
        scanf("%d",&n);
        f=(struct file*)malloc(n*sizeof(struct file));
        for(i=0;i<n;i++)
        {
            scanf("%s",f[i].day);
            scanf("%s",f[i].time);
            scanf("%d",&f[i].store);
            scanf("%s",f[i].name);
        }
        scanf("%s",s);
        scanf("%s",s);
        if(s[1]=='N')
        {
            qsort(f,n,sizeof(struct file),cmp1);
        }
        else if(s[1]=='S')
        {
            qsort(f,n,sizeof(struct file),cmp2);
        }
        else if(s[1]=='T')
        {
            qsort(f,n,sizeof(struct file),cmp3);
        }
        for(i=0;i<n;i++)
        {
            printf("%s %s %16d %s\n",f[i].day,f[i].time,f[i].store,f[i].name);
        }
        printf("\n");
    }while(n!=0);
    return 0;
}
