#include <stdio.h>

int main()
{
    char c1 = ' ', c2;
    int f = 0; //f=1表示正在读取16进制数
    int isans = 0;  //isans用于记录是否有合法的十六进制数
    unsigned int sum = 0;
    while ((c2 = getchar()) != EOF){
        if (c1 == '0' && c2 == 'x'){  //读取到0x则进入读取十六进制数的状态
            f = 1;
        }
        else if (f == 1){  //若正在读取数字
            if (c2 >= '0' && c2 <= '9'){
                sum = sum * 16 + c2 - '0';
            }
            else if (c2 >= 'a' && c2 <= 'f'){
                sum = sum * 16 + c2 - 'a' + 10;
            }
            else {
                printf("%u ", sum);
                sum = 0;
                isans = 1;
                f = 0;
            }
        }
        c1 = c2;
    }
    if (sum != 0) {
        printf("%u ", sum);
        isans = 1;
    }
    if (isans == 0) {
        printf("-1");
    }
    return 0;
}