#include <stdio.h>
#include <string.h>

int main()
{
    char a[501], b[501], p[501], q[501];
    while (scanf("%s %s", p, q) != EOF){
        int sign;  //sign记录A - B结果的正负
        if (strlen(p) > strlen(q)){  //比较A，B的大小
            strcpy(a, p); strcpy(b, q);
            sign = 1;
        }
        else if (strlen(p) < strlen(q)){
            strcpy(a, q); strcpy(b, p);
            sign = -1;
        }
        else {
            sign = strcmp(p, q);
            if (sign == 0){
                printf("0\n");  //两数相等则直接输出0
                continue;
            }
            else if (sign == 1){
                strcpy(a, p); strcpy(b, q);
            }
            else {
                strcpy(a, q); strcpy(b, p);
            }
        }
        int ans[501] = {0};
        int m = strlen(a) - 1, n = strlen(b) - 1, i = 0;
        int carry = 0;
        while (m >= 0 && n >= 0){  //计算A数和B数都有数字的位
            if (a[m] < b[n] + carry){
                ans[i++] = a[m] - b[n] + 10 - carry;
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

        //删去数字开头的0
        i --;
        while (ans[i] == 0){
            i --;
        }

        //输出
        if (sign == -1) printf("-");
        for (int j = i; j >= 0; j --){
            printf("%d", ans[j]);
        }
        printf("\n");
    }
    return 0;
}