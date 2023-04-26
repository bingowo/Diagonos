#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[30];
    int d;
}A;

int cmp(const void* _a, const void* _b)
{
    A *a = (A*)a;
    A *b = (A*)b;
    return (b->d - a->d) ? (b->d - a->d) : strcmp(a->id, b->id);
}

int getD(char s[])
{
    int count = 0;
    for(int i = 1; i < (int)strlen(s); i++)
    {
        if(s[0] != s[i]) count++;
    }
    return count;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        A a[1000];
        int n;
        scanf("%d",&n);
        for(int j = 0; j < n; j++)
        {
            scanf("%s",a[j].id);
            a[j].d = getD(a[j].id);
        }
        qsort(a, n, sizeof(A), cmp);
        printf("case #%d:\n",i);
        for (int j = 0; j < n; j++)
        {
            printf("%s",a[j].id);
        }
    }
    return 0;
}
