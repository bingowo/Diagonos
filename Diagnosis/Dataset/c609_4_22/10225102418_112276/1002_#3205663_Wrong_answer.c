#include <stdio.h>
#include <stdlib.h>
int longestSubStr(int p);
int main()
{
    int T;
    scanf("%d", &T);
    int *map = (int *)malloc(sizeof(int) * T);
    for (int i = 0; i < T; i++)
    {
        int temp;
        scanf("%d", &temp);
        map[i] = longestSubStr(temp);
        printf("case #%d\n", i);
        printf("%d\n", map[i]);
    }
    return 0;
}

int longestSubStr(int p)
{
    int t[32];
    int mark = 0;
    while (p)
    {
        t[mark] = p % 2;
        p /= 2;
        ++mark;
    }
    int last = -1;
    int cnt = 0;
    int itr = mark - 1;
    int max = 0;
    while (itr > -1)
    {
        if (last != t[itr])
        {
            ++cnt;
        }
        else
        {
            if (max < cnt)
            {
                max = cnt; // 更新最大值记录
            }
            cnt = 0; // cnt 复位
        }
        last = t[itr];
        itr--;
    }
    if (max < cnt)
    {
        max = cnt;
    }
    return cnt;
}
