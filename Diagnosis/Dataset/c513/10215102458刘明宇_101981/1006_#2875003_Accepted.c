#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d", &T); //测试数据组数
    int cnt = 0;
    while(cnt < T)
    {
        char str[100];
        scanf("%s", str);
        int len = strlen(str);//可正确输出输入的长度
        int high = 1;
        for(int j = 1;j < len;j++)
        {
            high *= 3;
        }
        int sum = 0;
        for(int i = 0;i < len;i++)
        {
            int x = 0;
            if(str[i] == '-') x = -1;
            if(str[i] == '0') x = 0;
            if(str[i] == '1') x = 1;
            sum += x * high;
            high = high / 3;
        }

        printf("case #%d:\n", cnt);
        printf("%d\n", sum);
        cnt++;
    }
}