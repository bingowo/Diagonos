#include <stdio.h>

int main()
{
    int prime[27] = {0,1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int cnt = 0, len = 2;
    int a[25] = {0}, num[40] = {0};
    do{
        scanf("%d",&a[cnt++]);
    }while(getchar() != '\n');
    for(int k=0; k<cnt; ++k) {
        int carry = 0;
        for(int i=0; i<len; ++i) {
            num[i] += a[k] % 10 + carry;
            carry = num[i] / 10;
            num[i] %= 10;
            a[k] /= 10;
        }
        if(carry) {
            num[len++] = carry;
            carry = 0
        }
        for(int i=0; i<len; ++i) {
            int t = num[i] * prime[cnt-k] + carry;
            num[i] = t % 10;
            carry = t / 10;
        }
        while(carry) {
            int t = num[len] + carry;
            num[len++] = t % 10;
            carry = t / 10;
        }
    }
    int i = 39;
    while(i>=0 && num[i]==0) --i;
    if(i < 0) printf("0");
    else for(; i>=0; --i) printf("%d",num[i]);
    printf("\n");
    return 0;
}