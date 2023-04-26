#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char time1[11]; char time2[6]; int size; char name[100];
}file;

int cmp_name(const void* a,const void* b)
{
    file* m = (file*)a, *n = (file*)b;
    return strcmp(m->name,n->name);
}

int cmp_size(const void* a,const void* b)
{
    file* m = (file*)a, *n = (file*)b;
    if(m->size == n->size)
        return strcmp(m->name,n->name);
    else
        return m->size - n->size;
}
int cmp_time(const void* a,const void* b)
{
    file* m = (file*)a, *n = (file*)b;
    int x = strcmp(m->time1,n->time1);
    if(x == 0)
     {
         if(strcmp(m->time2,n->time2) == 0)
            return strcmp(m->name,n->name);
         else
            return strcmp(m->time2,n->time2);
     }
    else
        return x;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        char order[11]={0};
        int i;
        file *list = (file*)malloc(sizeof(file)*n);
        for(i = 0;i<n;i++)
        {
            scanf("%s %s",list[i].time1,list[i].time2);
            scanf("%d %s",&list[i].size,list[i].name);
        }

		scanf("%s ",order);
		scanf("%s",order);

        if(order[1] == 'N')
            qsort(list,n,sizeof(file),cmp_name);
        else if(order[1] == 'S')
            qsort(list,n,sizeof(file),cmp_size);
        else
            qsort(list,n,sizeof(file),cmp_time);
        for(i=0;i<n;i++)
        {
            printf("%s %s ",list[i].time1,list[i].time2);
            printf("%16d %s\n",list[i].size,list[i].name);
        }
        free(list);
        putchar('\n');
        scanf("%d",&n);
    }

    return 0;
}

