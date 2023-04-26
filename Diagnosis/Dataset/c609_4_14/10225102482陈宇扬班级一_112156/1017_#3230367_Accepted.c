#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmpA(const void *a, const void *b) //升序
{
    return *(int *)a - *(int *)b;
}
int cmpD(const void *a, const void *b) //降序
{
    return *(int *)b - *(int *)a;
}
int main()
{
    int ch;
    int s[1001] = {0};
    int n, len = 0;
    int ans[1001] = {0};

    scanf("%c", &ch);
    while ((scanf("%d", &n)) != EOF)
        s[len++] = n;
    if (ch == 'A')
    {
        for (int i = 0; i < len; i++)
            qsort(s, len, sizeof(s[0]), cmpA);
    }
    else if (ch == 'D')
    {
        for (int i = 0; i < len; i++)
            qsort(s, len, sizeof(s[0]), cmpD);
    }

    int start = 0, end = 1, k = 0;
    while (end < len)
    {
        if (s[start] != s[end])
        {
            ans[k] = s[start];
            end++;
            start++;
            k++;
        }
        else
        {
            start++;
            end++;
        }
    }
    // end已越界
    ans[k] = s[start];
    k++;
    for (int j = 0; j < k; j++)
        printf("%d ", ans[j]);
    system("pause");
    return 0;
}
