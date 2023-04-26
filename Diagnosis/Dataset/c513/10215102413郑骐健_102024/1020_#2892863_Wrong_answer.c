#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct LIST
{
    char time1[200];
    char time2[200];//时刻
    int size;
    char name[200];
}List, * p_List;


int cmp_time(const void* p1, const void* p2)
{
    p_List p_1 = *(p_List*)p1;
    p_List p_2 = *(p_List*)p2;
    int a = strcmp(p_1->time1, p_2->time1);
    if (a != 0)return a;
    else if (strcmp(p_1->time2, p_2->time2))
    {
        return  strcmp(p_1->time2, p_2->time2);
    }
    else return cmp_name(p1, p2);
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
    if ((p_1->size > p_2->size))
        return 1;
    else if (p_1->size < p_2->size)return 0;
    else return strcmp(p_1->name, p_2->name);

}
void output(p_List* p1, int n)
{
    for (int i = 0;i < n;i++)
    {
        printf("%s %s %16d %s\n", p1[i]->time1, p1[i]->time2, p1[i]->size, p1[i]->name);

    }
    printf("\n");
}

int main()
{
    int n;
    while (scanf("%d", &n) !=EOF&&n!=0)
    {
    getchar();
        p_List* plist = (p_List*)malloc(sizeof(p_List) * (n + 200));
        for (int i = 0;i < n;i++)
        {
            plist[i] = (p_List)malloc(sizeof(List));
            scanf("%s%s%d%s",
                &(plist[i]->time1), &(plist[i]->time2), &(plist[i]->size), &(plist[i]->name));
        }
        char order[30];
        getchar();
        gets(order);
       
        //按时间
        if (!(strcmp(order, "LIST /TIME")))
        {
            qsort(plist, n, sizeof(p_List), cmp_time);
        }
        //  按大小
        else if (!strcmp(order, "LIST /SIZE"))
        {
            qsort(plist, n, sizeof(p_List), cmp_size);

        }
        else
        {
            qsort(plist, n, sizeof(p_List), cmp_name);

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
