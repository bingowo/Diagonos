#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned char c[100];
    int store;
    char day[18];
    char time[10];
}file;

int cmp_name(const void* a,const void* b)
{
    file x = *((file*)a);
    file y = *((file*)b);
    return strcmp(x.c,y.c);
}

int cmp_size(const void* a,const void* b)
{
    file x = *((file*)a);
    file y = *((file*)b);
    if(x.store!=y.store)return x.store-y.store;
    else return strcmp(x.c,y.c);
}

int cmp_time(const void* a,const void* b)
{
    file x = *((file*)a);
    file y = *((file*)b);
    if(strcmp(x.day,y.day)!=0)
    {
        return (strcmp(x.day,y.day));
    }
    else if(strcmp(x.time,y.time)!=0){
        return(strcmp(x.time,y.time));
    }
    else{
        return (strcmp(x.c,y.c));
    }

}

int main()
{
    int n;
    file s[120];
    while((scanf("%d",&n))!=EOF&&n!=0){
        for(int i=0;i<n;i++)
        {
            scanf("%s %s %d %s",&s[i].day,&s[i].time,&s[i].store,s[i].c);
        }
        char a[15];
        gets(a);
        gets(a);
        if(strstr(a,"LIST /NAME")!=NULL)qsort(s,n,sizeof(file),cmp_name);
        else if(strstr(a,"LIST /SIZE")!=NULL)qsort(s,n,sizeof(file),cmp_size);
        else if(strstr(a,"LIST /TIME")!=NULL)qsort(s,n,sizeof(file),cmp_time);
        for(int i=0;i<n;i++)
        {
            printf("%s %s %16d %s\n",s[i].day,s[i].time,s[i].store,s[i].c);
        }
        printf("\n");
    }
    return 0;
}
