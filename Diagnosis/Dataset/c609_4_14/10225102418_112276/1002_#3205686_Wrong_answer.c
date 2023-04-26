#include <stdio.h>
#include <stdlib.h>

int longestSubStr(int a)
{
    int *s = (int *)malloc(sizeof(int) * 32);
    int table[2] = {0, 1};
    int iter = 0;
    while (a)
    {
        s[iter] = table[a % 2];
        a /= 2;
        ++iter;
    }
    int cnt = 0;
    int maxCnt = 0;
    int last = -1;
    --iter;
    while (iter > -1)
    {
        if (s[iter] != last)
            cnt++;
        else
        {
            if (maxCnt < cnt)
                maxCnt = cnt;
            cnt = 1;
        }
        last = s[iter];
        --iter;
    }
    if (maxCnt < cnt)
        maxCnt = cnt;
    return maxCnt;
}

int main()
{
    int T;
    // cin >> T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        printf("case #%d\n", i);
        int n;
        scanf("%d", &n);
        printf("%d\n", longestSubStr(n));
    }
    return 0;
}