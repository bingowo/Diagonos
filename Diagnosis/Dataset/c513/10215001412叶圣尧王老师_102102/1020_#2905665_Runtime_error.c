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
        printf("%s %s%-17lld %s",file[i].data,file[i].time,file[i].size,file[i].name);











        scanf("%d",&n);
    }
}

