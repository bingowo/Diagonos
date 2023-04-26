#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s1[5]="NAME", s2[5]="SIZE", s3[5]="TIME";

typedef struct
{
    char date[20];
    char time[10];
    int size;
    char name[100];
} FILES;

int cmp1(const void* a,const void* b)
{
    FILES* pa=(FILES*)a; FILES* pb=(FILES*)b;
    return (strcmp(pa->name,pb->name)<0)?-1:1;
}

int cmp2(const void* a,const void* b)
{
    FILES* pa=(FILES*)a; FILES* pb=(FILES*)b;
    if (pa->size>pb->size) return 1;
    if (pa->size<pb->size) return -1;
    if (pa->size==pb->size)
    {
        return (strcmp(pa->name,pb->name)<0)?1:-1;
    }
}

int cmp3(const void* a,const void* b)
{
    FILES* pa=(FILES*)a; FILES* pb=(FILES*)b;
    if (strcmp(pa->date,pb->date)>0) return 1;
    if (strcmp(pa->date,pb->date)<0) return -1;
    if (strcmp(pa->date,pb->date)==0)
    {
        if (strcmp(pa->time,pb->time)>0) return 1;
        if (strcmp(pa->time,pb->time)<0) return -1;
        if (strcmp(pa->time,pb->time)==0)
        {
            return (strcmp(pa->name,pb->name)<0)?1:-1;
        }
    }
}

int main()
{
    int n=1,i;
    while (n)
    {
        scanf("%d",&n);
        FILES* arr=(FILES*)malloc(n*sizeof(FILES));
        for (i=0;i<n;i++)
        {
            scanf("%s",arr[i].date);
            scanf("%s",arr[i].time);
            scanf("%d",&arr[i].size);
            scanf("%s",arr[i].name);
        }
        char s[5]={0};
        getchar();
        scanf("LIST /%s",s);
        if (strcmp(s,s1)==0)
        {
            qsort(arr,n,sizeof(FILES),cmp1);
        }
        if (strcmp(s,s2)==0)
        {
            qsort(arr,n,sizeof(FILES),cmp2);
        }
        if (strcmp(s,s3)==0)
        {
            qsort(arr,n,sizeof(FILES),cmp3);
        }
        for (i=0;i<n;i++)
        {
            printf("%s ",arr[i].date);
            printf("%s ",arr[i].time);
            printf("%16d ",arr[i].size);
            printf("%s\n",arr[i].name);
        }
        printf("\n");

    }


    return 0;
}
