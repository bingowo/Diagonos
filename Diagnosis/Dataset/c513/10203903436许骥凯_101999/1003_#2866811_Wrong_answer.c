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
    else if (cntv == cntw){
        if (v < w) return 1;
    }
    return 0;
}

void exch(long long int* nums, int i, int j){
    long long int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void shell(long long int* nums, int hi){
    if (hi == 0) return;
    int h = 1;
    while (h < (hi+1) / 3) h = h * 3 + 1;
    while (h >= 1){
        for (int i = h; i <= hi; i++){
            for (int j = i; j >= h && compare(nums[j], nums[j-h]); j -= h)
                exch(nums, j, j-h);
        }
        h /= 3;
    }
}
int main(){
    int n;
    long long int nums[20000];
    scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int len, index = 0;
        scanf("%d", &len);
        for (; index != len && scanf("%lld", &nums[index++]););
        shell(nums, index-1);
        printf("case #%d:\n", i);
        for(int j = 0; j != index; j++)
            printf("%lld ", nums[j]);
        printf("\n");
    }
}