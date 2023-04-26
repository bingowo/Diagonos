#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    int n1 = *(int*)a;int num1=n1;
    int n2 = *(int*)b;int num2=n2;
    int digit1 = 0, digit2 = 0;
    do{
        digit1++;
        num1 /= 10;
    }while (num1 != 0);
    do{
        digit2++;
        num2 /= 10;
    }while (num2 != 0);//0的位数为1；
    if (digit1 == digit2) {
        return n1 - num2;
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
