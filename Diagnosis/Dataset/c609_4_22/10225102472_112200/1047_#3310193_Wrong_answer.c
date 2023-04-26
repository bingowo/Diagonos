#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000
int num[MAX_LEN];
void power(int a, int n) {
    memset(num, 0, sizeof(num));
    num[0] = 1;
    for (int i = 0; i < n; i++) {
        int carry = 0;
        for (int j = 0; j < MAX_LEN; j++) {
            int temp = num[j] * a + carry;
            num[j] = temp % 10;
            carry = temp / 10;
        }
    }
}

void print_num() {
    int high = MAX_LEN - 1;
    while (high > 0 && num[high] == 0) {
        high--;
    }
    for (int i = high; i >= 0; i--) {
        printf("%d", num[i]);
    }
    printf("\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int k=0; k<T; k++)
    {
        int a, n;
        scanf("%d %d", &a, &n);
        power(a, n);
        printf("case #%d:\n", k+1);
        print_num();
    }
    return 0;
}