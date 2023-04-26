#include<stdio.h>

void reverse(char* nums, int hi){
    int beg = 0;
    while (beg <= hi){
        char temp = nums[beg];
        nums[beg++] = nums[hi];
        nums[hi--] = temp;
    }
}
void transform(int num, int fac){
    char nums[50];
    int i = 0, flag= 0;
    if (num < 0) {flag = 1; num = -num;}
    while(num){
        int res = num % fac;
        if (res >= 10)
            nums[i++] = res - 10 + 'A';
        else 
            nums[i++] = res + '0';
        num /= fac;
    }
    reverse(nums, i-1);
    if (flag) printf("-");
    for (int j = 0; j != i; j++)
        printf("%c", nums[j]);
    printf("\n");
}
int main(){
    int n, num, fac;
    scanf("%d", &n);
    for (int i = 0; i != n && scanf("%d%d", &num, &fac); i++)
        transform(num, fac);
    return 0;
}


