#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct LIST
{
    char time1[200];
    char time2[200];//时刻
    char size[200];
    char name[200];
}List,*p_List;


int cmp_time(const void* p1, const void* p2)
{
    p_List p_1 = *(p_List*)p1;
    p_List p_2 = *(p_List*)p2;
    int a = strcmp(p_1->time1, p_2->time1);
    if (a != 0)return a;
    else
    {
       return  strcmp(p_1->time2, p_2->time2);
    }
     
}
int cmp_name(const void* p1, const void* p2)
{
    p_List p_1 = *(p_List*)p1;
    p_List p_2 = *(p_List*)p2;
    return strcmp(p_1->name, p_2->name);
}
int cmp_size(const void* p1, const void* p2)
{
    p_List p_1 = *(p_List*)p1;
    p_List p_2 = *(p_List*)p2;
    return strcmp(p_1->size, p_2->size);
}
void output(p_List* p1,int n)
{
    for (int i = 0;i < n;i++)
    {
        printf("%s %s %+16s %s\n", p1[i]->time1, p1[i]->time2, p1[i]->size, p1[i]->name);
     
    }
    printf("\n");
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        p_List* plist = (p_List*)malloc(sizeof(p_List)*n);
        getchar();
        for (int i = 0;i < n;i++)
        {
            plist[i] = (p_List)malloc(sizeof(List));
            scanf("%s%s%s%s",
                &(plist[i]->time1), &(plist[i]->time2), &(plist[i]->size), &(plist[i]->name));
            getchar();
        }
        char order[30];
        gets(order);
        //按时间
        if (!(strcmp(order, "LIST /TIME")))
        {
            qsort(plist, n, sizeof(p_List),cmp_time );
        }
            //  按大小
        else if (!strcmp(order, "LIST /SIZE"))
        {
            qsort(plist, n, sizeof(p_List),cmp_size );

        }
        else
        {
            qsort(plist, n, sizeof(p_List),cmp_name );

        }
        output(plist, n);
        for (int i = 0;i < n;i++)
        {
            free(plist[i]);
        }
        free(plist);
    }
    return 0;

}
