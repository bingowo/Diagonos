#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sss {
    int num;
    char ss[21];
};
int cmp(const void* _a, const void* _b)
{
    struct sss* a = (struct sss*)_a;
    struct sss* b = (struct sss*)_b;
    if (a->num == b->num)
    {
        return strcmp(a->ss, b->ss);
    }
    else
        return b->num - a->num;
}
int getnum(char s[])//得到字符串中不同字符的个数
{
    int flag[26] = { 0 };
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (flag[s[i] - 65] == 0) count++;
        flag[s[i] - 65]++;
    }
    return count;
}

int main()
{
    int t;
    scanf("%d", &t);
    int n;
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        struct sss s[n];
        for (int j = 0; i < n; j++)
        {
            scanf("%s",s[j].ss);
            s[j].num = getnum(s[j].ss);
        }
        printf("case #%d:\n", i);
        qsort(s, n, sizeof(s[0]), cmp);
        for (int z = 0; z < n; z++)
        {
            printf("%s\n", s[z].ss);
        }
    }
    return 0;
}