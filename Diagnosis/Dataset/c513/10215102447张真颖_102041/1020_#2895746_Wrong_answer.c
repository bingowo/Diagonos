#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char time[17];
    long int size;
    char name[63];
}LIST;

LIST* Input(int n)
{
    LIST* a=(LIST*)malloc(sizeof(LIST)*n);
    int i;
    for(i=0;i<n;i++)
        scanf("%s%ld%s",a[i].time,&a[i].size,a[i].name);
    return a;
}

int cmp_name(const void* a,const void* b)
{
    LIST *pa=(LIST*)a,*pb=(LIST*)b;
    return strcmp(pa->name,pb->name);
}

int cmp_size(const void* a,const void* b)
{
    LIST *pa=(LIST*)a,*pb=(LIST*)b;
    if(pa->size > pb->size) return 1;
    if(pa->size < pb->size) return -1;
    return strcmp(pa->name,pb->name);
}

int cmp_time(const void*a,const void* b)
{
    LIST *pa=(LIST*)a,*pb=(LIST*)b;
    int i;
    for(i=0;i<16;i++)
    {
        if((pa->time[i])>='0'&&(pa->time[i])<='9'&&(pb->time[i])>='0'&&(pb->time[i])<='9')
        {
            if(pa->time[i]>pb->time[i]) return 1;
            else if(pa->time[i]<pb->time[i]) return -1;
        }
    }
    if(i)
        return strcmp(pa->name,pb->name);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
    if(n)
    {
        LIST* a=NULL;
        char command[12];
        a=Input(n);
        scanf("%s",command);
        if(strcmp(command,"LIST /NAME")==0)
            qsort(a,n,sizeof(LIST*),cmp_name);
        else if(strcmp(command,"LIST /SIZE")==0)
            qsort(a,n,sizeof(LIST*),cmp_size);
        else
            qsort(a,n,sizeof(LIST*),cmp_time);
        for(int i=0;i<n;i++)
            printf("%s%16d %s\n",a[i].time,a[i].size,a[i].name);
        free(a);

    }
    else break;
    }
    return 0;
}