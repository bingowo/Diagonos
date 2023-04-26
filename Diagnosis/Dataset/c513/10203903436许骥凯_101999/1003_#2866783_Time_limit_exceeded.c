#include<stdio.h>

int compare(long long int v, long long int w){
    int cntv = 0, cntw = 0;
    long long int flag = 1;
    for (int i = 0; i != 63; i++){
        if (flag & v) cntv++;
        if (flag & w) cntw++;
        flag <<= 1;
    }
    if (cntv > cntw) return 1;
    if (cntv == cntw){
        if (v < w) return 1;
    }
    return 0;
}

void exch(long long int* nums, int i, int j){
    long long int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void insert(long long int* nums, long long int num, int hi){
    nums[hi] = num;
    for (int i = hi; i >= 1; i--)
        if (compare(nums[i], nums[i-1]))
            exch(nums, i, i-1);
}
int main(){
    int n;
    long long int num;
    long long int nums[10001];
    scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int len, index = 0;
        scanf("%d", &len);
        for (; index != len; index++){
            scanf("%lld", &num);
            insert(nums, num, index);         
        }
        printf("case #%d:\n", i);
        for(int j = 0; j != index; j++)
            printf("%lld ", nums[j]);
        printf("\n");
    }
}