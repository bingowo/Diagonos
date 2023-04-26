#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 利用数组计次优化为二层循环
int main()
{
    char str[100006];
    scanf("%s",str);
    int maxlen = 0;
    int start = 0;
    for (int i = 0;str[i];)
    {
        int C[128] = {0};
        int length = 0;
        int j = 0;
        for ( j = i;str[j] && C[str[j]] == 0;++j)
        {
            C[str[j]] = 1;
            length ++;
        }
        i = j;   // 跳过重复查找
        if (maxlen < length)
        {
            start = j-length;maxlen = length;
        }
    }
    for (int i = start;i<start + maxlen;i++)  printf("%c",str[i]);
    printf("\n");
    return 0;
}
