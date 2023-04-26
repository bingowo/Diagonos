#include <stdio.h>
#include <string.h>

int main()
{
    char a[501], b[501];
    while (scanf("%s %s", a, b) != EOF){  //计算A数和B数都有数字的位
        int ans[501] = {0};
        int m = strlen(a) - 1, n = strlen(b) - 1, i = 0;
        int carry = 0;
        while (m >= 0 && n >= 0){
            if (a[m] < b[n] + carry){
                ans[i++] = a[m] + 10 - b[n] - carry;
                carry = 1;
            }
            else{
                ans[i++] = a[m] - b[n] - carry;
                carry = 0;
            }
            m --;
            n --;
        }
        while (m >= 0){  //计算A数多于B数的位
            if (a[m] - '0' < carry){
                ans[i++] = a[m] - '0' - carry + 10;
                carry = 1;
            }
            else{
                ans[i++] = a[m] - '0' - carry;
                carry = 0;
            }
            m --;
        }
        i --;
        while (ans[i] == 0){  //删去数字开头的0
            i --;
        }
        for (int j = i; j >= 0; j --){  //输出
            printf("%d", ans[j]);
        }
        printf("\n");
    }
    return 0;
}