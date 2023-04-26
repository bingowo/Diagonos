#include <stdio.h>
#include <stdlib.h>

int cmp_A(const void* p1, const void* p2) {
    return *(int*)p1 - *(int*)p2;
}

int cmp_D(const void* p1, const void* p2) {
    return cmp_A(p2, p1);
}

int main() {
    char c = getchar();
    int nums[100], num_len = 0;
    while (~scanf("%d", &nums[num_len++]))
        ;
    --num_len;
    if (c == 'A')
        qsort(nums, num_len, sizeof(int), cmp_A);
    else if (c == 'D')
        qsort(nums, num_len, sizeof(int), cmp_D);

    int* ptr_last = nums;
    for (int i = 0; i != num_len - 1; ++i) {
        if (nums[i] != nums[i + 1])
            *++ptr_last = nums[i + 1];
    }
    for (int* i = nums; i <= ptr_last; ++i)
        printf("%d%c", *i, i == ptr_last? '\n' : ' ');
    return 0;
}