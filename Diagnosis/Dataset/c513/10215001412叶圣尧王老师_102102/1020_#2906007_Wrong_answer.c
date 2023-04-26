#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct st
{
    char data[11];
    char time[6];
    char size[17];
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
     return strcmp(c->size,d->size);
}

int cmp3(const void*a,const void *b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(strcmp(c->data,d->data)>0)return 1;
    else if(strcmp(c->data,d->data)<0)return -1;
    else if(strcmp(c->time,d->time)==0)return strcmp(c->name,d->name);
    else return strcmp(c->time,d->time);
}

int main()
{
    int n,i,k=0;
    scanf("%d",&n);
    while(n!=0)
    { 
        struct st file[n];
       for(i=0;i<n;i++)scanf("%s%s%s%s",file[i].data,file[i].time,file[i].size,file[i].name);
       char s1[10];char s[10];
       scanf("%s %s",s1,s);
        if(s[1]=='N')qsort(file,n,sizeof(struct st),cmp1);
        else if(s[1]=='S')qsort(file,n,sizeof(struct st),cmp2);
        else if(s[1]=='T')qsort(file,n,sizeof(struct st),cmp3);
        for(i=0;i<n;i++)printf("%s %s %16s %s\n",file[i].data,file[i].time,file[i].size,file[i].name);
        scanf("%d",&n);
        if(n!=0)printf("\n");
    }
}
