#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file
{
    char date[20];
    char time[10];
    long long int size;
    char name[100];
};
char list[20];

int cmp(const void*a,const void*b)
{
    struct file *c=(struct file*)a;
    struct file *d=(struct file*)b;
    if(list=="LIST /NAME")
    {
        return strcmp(c->name,d->name);
    }
    else if(list=="LIST /SIZE")
    {
        if(c->size > d->size)
            return 1;
        else if(c->size < d->size)
            return -1;
        else return strcmp(c->name,d->name);
    }
    else
    {
        if(c->time != d->time)
            return strcmp(c->time,d->time);
        else
            return strcmp(c->name,d->name);
    }
}
int main()
{
    int n,i;
    while(scanf("%d",&n) && n!='0')
    {
        struct file f[101];
        for(i=0;i<n;i++)
        {
            scanf("%s",f[i].date);
            scanf("%s",f[i].time);
            scanf("%lld",&f[i].size);
            scanf("%s",f[i].name);
        }
        scanf("%s",list);
        qsort(f,n,sizeof(f[0]),cmp);
        for(i=0;i<n;i++)
        {
            printf("%s ",f[i].date);
            printf("%s ",f[i].time);
            printf("%16lld ",f[i].size);
            printf("%s\n",f[i].name);
        }
        printf("\n");
    }

    return 0;
}
