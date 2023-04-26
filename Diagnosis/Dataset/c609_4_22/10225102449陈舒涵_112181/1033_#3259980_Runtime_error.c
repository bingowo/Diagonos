#include <stdio.h>

int main()
{
    int T, i, j, d, r, n, sum;
    char c;
    char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-";
    scanf("%d", &T);
    getchar();
    for (int t = 0; t < T; t ++){
        i = 0; n = 0;
        int a[800] = {0};
        while ((c = getchar()) != '\n'){
            n ++;
            d = (int)c;
            i = n * 8 - 1;
            while (d > 0){
                a[i] = d % 2;
                d /= 2;
                i --;
            }  //将所有字符的二进制直接连接
        }
        i = 8 * n;
        while (i % 6 != 0){
            i ++;
        }  //字节数不是3的倍数，填充至位数是6的倍数
        j = i / 6;
        printf("case #%d:\n", t);
        for (int p = 0; p < j; p ++){
            sum = 0;
            for (int q = p * 6; q < p * 6 + 6; q ++){
                sum = sum * 2 + a[q];
            }
            printf("%c", s[sum]);
        }
        while (j % 4 != 0){
            printf("=");
            j ++;
        }
        printf("\n");
    }
    return 0;
}