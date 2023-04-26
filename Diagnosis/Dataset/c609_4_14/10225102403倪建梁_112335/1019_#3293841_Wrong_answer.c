#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    int digit1 = 0, digit2 = 0;
    while (num1 != 0) {
        digit1++;
        num1 /= 10;
    }
    while (num2 != 0) {
        digit2++;
        num2 /= 10;
    }
    if (digit1 == digit2) {
        return num1 - num2;
    } else {
        return digit2 - digit1;
    }
}
int main() {
    int n=0,num, nums[1000000];
    while (scanf("%d", &num) != EOF) nums[n++] = num;
    qsort(nums, n, sizeof(int), compare);
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}
