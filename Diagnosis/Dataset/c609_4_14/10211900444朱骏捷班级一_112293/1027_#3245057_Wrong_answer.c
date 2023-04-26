#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char id[12];
    int score;
} stu;

int cmp(stu *a, stu *b)
{
    int n = a->score - b->score;
    if(n != 0)
        return n;
    n = strcmp(b->id, a->id);
    if(n != 0)
        return n;
}

void swap(stu *a,stu *b)
{
    stu temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(stu a[],int n)
{
    for(int i = 0; i < n; i++)
    {
        int flag = i;
        for(int j = i + 1; j < n; j++)
        {
            if(cmp(&a[j], &a[flag]) > 0)
                flag = j;
        }
        swap(&a[i], &a[flag]);
    }
}

int main()
{
    int n;
    stu a[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %d", &a[i].id, &a[i].score);
    }
    sort(a, n);
    for(int i = 0; i < n; i++)
    {
        if(a[i].score>=60)
            printf("%s %d\n", a[i].id, a[i].score);
    }
    return 0;
}