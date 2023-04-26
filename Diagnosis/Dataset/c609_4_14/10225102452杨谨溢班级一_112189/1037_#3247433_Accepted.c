#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 利用数组计次优化为二层循环
int main()
{
    char str[1000006];
    scanf("%s",str);
    int maxlen = 0;
    int start = 0;
    int t = 0;
    int C[128];
    for (int i =0;i<128;i++)  C[i] = -1;

    for (int i = 0;str[i];i++)
    {
        /*int length = 0;
        int j = 0;
        for ( j = i;str[j] && C[str[j]] == -1;++j)
        {
            C[str[j]] = j;  // 记录位置
            length ++;
        }
        //  i = j;   // 跳过重复查找, 但是这样写有一点点问题
        i = j;
        if (maxlen < length)
        {
            start = C[str[j]] ;maxlen = length;
        }*/
        char c = str[i];
        if (C[c] >= t)
        {
            t = C[c] + 1;
            C[c] = i;
        }
        else
        {
            C[c] = i;
            if (maxlen<i-t+1)
            {
                start = t;
                maxlen = i - t+ 1;
            }
        }
    }
    for (int i = start;i<start + maxlen;i++)  printf("%c",str[i]);
    printf("\n");
    // getchar();
    return 0;
}
