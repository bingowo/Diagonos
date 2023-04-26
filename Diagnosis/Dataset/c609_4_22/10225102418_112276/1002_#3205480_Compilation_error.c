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
    int last = t[mark - 1];
    int cnt = 0;
    for (int i = mark - 1; i > 0; i--)
    {
        if (last != t[i - 1])
        {
            ++cnt;
            last = t[i - 1]
        }
        else
        {
            break;
        }
    }
    return cnt;
}
