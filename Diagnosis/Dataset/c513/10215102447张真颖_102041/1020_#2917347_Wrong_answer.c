#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char time[17];
    long long size;
    char name[127];
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
    char name[11]="LIST /NAME",size[11]="LIST /SIZE";
    for(int i=0;scanf("%d",&n)!=EOF&&n;i++)
    {
        if(i>0) printf("\n");
        LIST* a=NULL;
        a=(LIST*)malloc(sizeof(LIST)*n);
        char command[11]="";
        getchar();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<16;j++)
                a[i].time[j]=getchar();
            a[i].time[16]=0;
            scanf("%lld %s",&a[i].size,a[i].name);
            getchar();
        }
        for(int i=0;i<10;i++)
            command[i]=getchar();
        command[10]=0;
        if(strcmp(command,name)==0)
            qsort(a,n,sizeof(a[0]),cmp_name);
        else if(strcmp(command,size)==0)
            qsort(a,n,sizeof(a[0]),cmp_size);
        else
            qsort(a,n,sizeof(a[0]),cmp_time);
        for(int i=0;i<n;i++)
            {

                printf("%s%16lld %s\n",a[i].time,a[i].size,a[i].name);
            }
        free(a);
        n=0;
     }
    return 0;
}