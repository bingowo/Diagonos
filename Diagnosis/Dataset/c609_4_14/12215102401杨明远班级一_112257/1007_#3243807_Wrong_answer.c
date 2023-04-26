#include <stdlib.h>
#include <stdint.h>
#define N 10000
// 函数声明
int cmp(const void* a, const void* b);
int bitcount(uint64_t n);

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) { 
        // 读取所有数并排序
        int64_t nums[N];
        for (int j = 0; j < N; j++) {
            scanf("%lld", &nums[j]);
        }
        qsort(nums, N, sizeof(int64_t), cmp);

        // 根据二进制中1的个数排序
        qsort(nums, N, sizeof(int64_t), bitcount);

        // 输出结果
        printf("case #%d: ", i);
        for (int j = 0; j < N; j++) {
            printf("%lld ", nums[j]);
        }
        printf("\n");
    }

    return 0;
}

// 比较函数：先比较二进制中1的个数，再比较数本身大小
int cmp(const void* a, const void* b)
{
    int64_t x = *(int64_t*)a;
    int64_t y = *(int64_t*)b;

    int count1_x = bitcount((uint64_t)x);
    int count1_y = bitcount((uint64_t)y);

    if (count1_x != count1_y) {
        return count1_y - count1_x;
    }
    else {
        return x - y;
    }
}

// 计算二进制中1的个数
int bitcount(uint64_t n)
{
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}
