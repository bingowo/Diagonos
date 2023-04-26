#include<stdio.h>
#include<stdlib.h>

int compare(const void *p1, const void *p2){
    return *(int*)p1 - *(int*)p2;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int nums;
        scanf("%d", &nums);
        int *num1 = (int*)malloc(sizeof(int) * nums);
        int *num2 = (int*)malloc(sizeof(int) * nums);
        for (int j = 0; j != nums; j++)
            scanf("%d", &num1[j]);
        for (int j = 0; j != nums; j++)
            scanf("%d", &num2[j]);
        qsort(num1, nums, 4, compare);
        qsort(num2, nums, 4, compare);
        int sum = 0;
        for (int j = 0; j != nums; j++)
            sum += num1[j] * num2[nums-1-j];
        printf("case #%d:\n%d\n", i, sum);
        free(num1), free(num2);
    }
    return 0;
}