#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct STU
{   unsigned char name[64];
    int size;
    char day[11],time[10];
}stu;
int cmp_NAME(const void* _a, const void* _b)
{
    stu* a = (stu*)_a;  stu* b = (stu*)_b;
    return (strcmp(a->name, b->name));
}
int cmp_SIZE(const void* _a, const void* _b)
{
    stu* a = (stu*)_a;  stu* b = (stu*)_b;
    if (a->size != b->size)   return ((a->size) > (b->size) ? 1 : -1);
    else  return (strcmp(a->name, b->name));
}
int cmp_TIME(const void* _a, const void* _b)
{
    stu* a = (stu*)_a;  stu* b = (stu*)_b;
    if (strcmp(a->day, b->day) != 0) return (strcmp(a->day, b->day));
    else if (strcmp(a->time, b->time) != 0) return (strcmp(a->time, b->time));
    else   return (strcmp(a->name, b->name));
}
int main()
{
    int n, x = 1; char a[15];  stu s[120];
    scanf("%d", &n);
    while (n != 0)
    {
        if (x != 1)   printf("\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s[i].day);    scanf("%s", s[i].time);
            scanf("%d", &s[i].size);  scanf("%s", s[i].name);
        }
        gets(a);  gets(a);
        if (a[6] == 'N') qsort(s, n, sizeof(stu), cmp_NAME);
        else if (a[6] == 'S') qsort(s, n, sizeof(stu), cmp_SIZE);
        else if (a[6] == 'T') qsort(s, n, sizeof(stu), cmp_TIME);
        for (int i = 0; i < n; i++)
            printf("%s %s %16d %s\n", s[i].day, s[i].time, s[i].size, s[i].name);
        x = 0;
        scanf("%d", &n);
    }
    return 0;
}