#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct st
{
    char data[11];
    char time[6];
    long long size;
    char name[100];
};

int cmp1(const void*a,const void *b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    return strcmp(c->name,d->name);
}

int cmp2(const void*a,const void *b)
{ 
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(c->size==d->size)return strcmp(c->name,d->name);
    return c->size-d->size;
}

int cmp3(const void*a,const void *b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(strcmp(c->data,d->data)!=0)return strcmp(c->data,d->data);
    else if(strcmp(c->time,d->time)!=0)return strcmp(c->time,d->time);
    else return strcmp(c->name,d->name);
}

int main()
{
    int n,i;
    scanf("%d",&n);
    while(n!=0)
    { 
        struct st file[n];
       for(i=0;i<n;i++)scanf("%s%s%lld%s",file[i].data,file[i].time,&file[i].size,file[i].name);
       char s1[10];char s[10];
       scanf("%s %s",s1,s);
        if(s[1]=='N')qsort(file,n,sizeof(struct st),cmp1);
        else if(s[1]=='S')qsort(file,n,sizeof(struct st),cmp2);
        else if(s[1]=='T')qsort(file,n,sizeof(struct st),cmp3);
        for(i=0;i<n;i++)printf("%s %s %16lld %s\n",file[i].data,file[i].time,file[i].size,file[i].name);
        scanf("%d",&n);
        if(n!=0)printf("\n");
    }
}
