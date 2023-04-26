#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char time[10];
    char day[20];
    int size;
    unsigned char name[70];
}LIST;

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
    if(strcmp(pa->day,pb->day))
    {return strcmp(pa->day,pb->day);}
    else if(strcmp(pa->time,pb->time))
    {return strcmp(pa->time,pb->time);}
    else return strcmp(pa->name,pb->name);
}


int main()
{
    int n;
    LIST a[100]={0};
    while((scanf("%d",&n))!=EOF&&n)
    {
        char command[15]="";
        for(int i=0;i<n;i++)
        {
            scanf("%s %s %d %s",a[i].day,a[i].time,&a[i].size,a[i].name);
        }
        gets(command);
        gets(command);
        if(strstr(command,"LIST /NAME")!=NULL)
            qsort(a,n,sizeof(a[0]),cmp_name);
        else if(strstr(command,"LIST /SIZE")!=NULL)
            qsort(a,n,sizeof(a[0]),cmp_size);
        else
            qsort(a,n,sizeof(a[0]),cmp_time);
        for(int i=0;i<n;i++)
            {
                printf("%s %s %16d %s\n",a[i].day,a[i].time,a[i].size,a[i].name);
            }
        printf("\n");
     }
    return 0;
}