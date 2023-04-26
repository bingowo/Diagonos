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
    {
        getchar();
        for(int j=0;j<16;j++)
            a[i].time[j]=getchar();
        a[i].time[16]=0;
        scanf("%ld %s",&a[i].size,a[i].name);
        a[i].name[strlen(a[i].name)]=0;
    }
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
    char name[11]="LIST /NAME",size[11]="LIST /SIZE";
    while(scanf("%d",&n)!=EOF){
    if(n)
    {
        LIST* a=NULL;
        char command[12];
        a=Input(n);
        getchar();
        gets(command);
        if(strcmp(command,name)==0)
            qsort(a,n,sizeof(a[0]),cmp_name);
        else if(strcmp(command,size)==0)
            qsort(a,n,sizeof(a[0]),cmp_size);
        else
            qsort(a,n,sizeof(a[0]),cmp_time);
        for(int i=0;i<n;i++)
            printf("%s%16ld %s\n",a[i].time,a[i].size,a[i].name);
        printf("\n");
        free(a);

    }
    else break;
    }
    return 0;
}
