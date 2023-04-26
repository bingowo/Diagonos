#include<stdio.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2){
    return *(long long int *)p1 > *(long long int*)p2? 1: -1;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    long long int *nums = (long long int*)malloc(sizeof(long long int) * n);
    for (int i = 0; i != n && scanf("%lld", &nums[i]); i++);
    qsort(nums, n, sizeof(nums[0]), cmp);
    long long int sum = 1LL << 62;
    for (int i = 0; i <= n - m; i++){
        long long int temp = 0;
        for (int j = i; j != i + m; j++)
            temp += nums[i + m - 1] - nums[j];
        sum = (temp > sum? sum: temp);
    }
    printf("%lld\n", sum); 
    free(nums);
    return 0;
}