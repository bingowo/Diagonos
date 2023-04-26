#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[21];
    int d;//d代表字符串中不同字符个数
}A;

int cmp(const void* _a, const void* _b)
{
    A a,b;
    a = *((A*)_a);
    b = *((A*)_b);
    if (a.d != b.d)
    {
        return b.d - a.d;
    }
    else
    {
        return strcmp(a.id, b.id);
    }
}

int getD(A s)
{
    int flag[26] = { 0 };
    int count = 0;
    for(int i = 0; s.id[i] != '\0'; i++)
    {
        if(flag[s.id[i]-65] == 0) count ++;
        flag[s.id[i]-65]++;
    }
    return count;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d",&n);
        A a[n];
        for(int j = 0; j < n; j++)
        {
            scanf("%s",a[j].id);
            a[j].d = getD(a[j]);
        }
        qsort(a,n,sizeof(a[0]),cmp);//qsort函数有问题
        printf("case #%d:\n",i);
        for (int j = 0; j < n; j++)
        {
            printf("%s\n",a[j].id);
        }
    }
    return 0;
}
