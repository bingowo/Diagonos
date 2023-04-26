#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int z = 0; z < T; z++)
    {
        unsigned long long f[1000010] = {0}; // 数组初始化为0
        int n, k;
        scanf("%d", &n);
        f[0] = 1;                    // 初始条件
        for (int i = 1; i <= n; i++) // 进行遍历递推
        {
            for (int j = 1; j <= 4 && i - j >= 0; j++) // 阶数最少1到最大k阶依次累加
                f[i] += f[i - j];
            // f[i] ; // 求模，防止溢出
        }
        printf("%llu", f[n]);
    }
    return 0;
}