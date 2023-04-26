#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct st
{
    char data[11];
    char time[6];
    long long size;
    char name[64];
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
    return c->size-d->size;
}

int cmp3(const void*a,const void *b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(strcmp(c->data,d->data)>0)return 1;
    else if(strcmp(c->data,d->data<0))return -1;
    else {return strcmp(c->time-d->time);}
}

int main()
{
    int n,i;
    scanf("%d",&n);struct st file[n];
    while(n!=0)
    {
       for(i=0;i<n;i++)scanf("%s%s%lld%s",file[i].data,file[i].time,&file[i].size,file[i].name);
       char s1[5];char s[6];
       scanf("%s %s",s1,s);
        if(s[1]=='N')qsort(file,n,sizeof(struct st),cmp1);
        else if(s[1]=='S')qsort(file,n,sizeof(struct st),cmp2);
        else qsort(file,n,sizeof(struct st),cmp3);
        for(i=0;i<n;i++)printf("%s %s%17lld %s\n",file[i].data,file[i].time,file[i].size,file[i].name);
        printf("\n");
        scanf("%d",&n);
    }
}
