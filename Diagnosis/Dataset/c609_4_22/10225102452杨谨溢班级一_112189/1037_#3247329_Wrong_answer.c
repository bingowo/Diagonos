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
    for (int i = 0;str[i];i++)
    {
        int C[128];
        for (int i =0;i<128;i++)  C[i] = -1;
        int length = 0;
        int j = 0;
        for ( j = i;str[j] && C[str[j]] == -1;++j)
        {
            C[str[j]] = j;
            length ++;
        }
        //  i = j;   // 跳过重复查找, 但是这样写有一点点问题
        i = j;
        if (maxlen < length)
        {
            start = C[str[j]] ;maxlen = length;
        }
    }
    for (int i = start;i<start + maxlen;i++)  printf("%c",str[i]);
    printf("\n");
    return 0;
}
