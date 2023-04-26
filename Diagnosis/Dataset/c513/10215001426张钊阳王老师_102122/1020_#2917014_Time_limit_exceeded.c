#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fileo
{
    char date[20];
    char time[20];
    char size[10];
    unsigned char name[64];
};

int main()
{
    void cmptime(struct fileo* a,int l);
    void cmpname(struct fileo* a,int l);
    void cmpsize(struct fileo* a,int l);
    int m;
    while(1)
    {
        char k[20];
        char k1[20];
        scanf("%d",&m);
        if(m==0) break;
        struct fileo* file=(struct fileo*)malloc(sizeof(struct fileo)*m);
        for(int z=0;z<m;z++)
        {
            scanf("%s",file[z].date);
            scanf("%s",file[z].time);
            scanf("%s",file[z].size);
            scanf("%s",file[z].name);
        }
        scanf("%s",k);
        scanf("%s",k1);
        if(k1[1]=='T') cmptime(file,m);
        if(k1[1]=='N') cmpname(file,m);
        if(k1[1]=='S') cmpsize(file,m);
        for(int z=0;z<m;z++)
        {
            printf("%s",file[z].date);
            printf(" ");
            printf("%s",file[z].time);
            int l=strlen(file[z].size);
            for(int u=0;u<17-l;u++) printf(" ");
            printf("%s",file[z].size);
            printf(" ");
            printf("%s\n",file[z].name);
        }
        printf("\n");
    }
    return 0;
}

void cmpname(struct fileo* a,int l)
{
    int i;
    struct fileo temp;
    int count;
    while(1)
    {
        count=0;
        for(i=0;i<l-1;i++)
        {
            if(strcmp(a[i].name,a[i+1].name)>0)
            {temp=a[i]; a[i]=a[i+1]; a[i+1]=temp;count++;}
        }
        if(count==0) break;
    }
}

void cmpsize(struct fileo* a,int l)
{
    int count;
    struct fileo temp;
    int* le=(int *)malloc(sizeof(int)*l);
    for(int s=0;s<l;s++)
    {
        le[s]=strlen(a[s].size);
    }
    while(1)
    {
        count=0;
        for(int i=0;i<l-1;i++)
        {
            if(le[i]>le[i+1])
                {temp=a[i]; a[i]=a[i+1]; a[i+1]=temp;count++;}
            else if(le[i]==le[i+1])
                {
                    if(strcmp(a[i].name,a[i+1].name)>0)
                     {temp=a[i]; a[i]=a[i+1]; a[i+1]=temp;count++;}
                }
        }
        if(count==0) break;
    }
}

void cmptime(struct fileo* a,int l)
{
    int i,count;
    struct fileo temp;
    char to[50][50];
    for(int z=0;z<l;z++)
    {
        strcpy(to[z],a[z].date);
        strcpy(to[z],a[z].time);
    }
    while(1)
    {
        count=0;
        for(i=0;i<l-1;i++)
        {
                if(strcmp(to[i],to[i+1])>0)
                {temp=a[i]; a[i]=a[i+1]; a[i+1]=temp;count++;}
        }
        if(count==0)
            {
                if(strcmp(a[i].name,a[i+1].name)>0)
                     {temp=a[i]; a[i]=a[i+1]; a[i+1]=temp;count++;}
            }
        if(count==0) break;
    }
}





