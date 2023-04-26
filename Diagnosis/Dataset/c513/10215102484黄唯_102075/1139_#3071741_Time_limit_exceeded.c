#include<stdlib.h>
#include<stdio.h>



int isValid(int n)
{
    int ret = 1;
    while (n) {
        if (n % 10 != 0 && n % 10 != 1) {
            ret = 0;
            break;
        }
       // n /= 10;
    }
    return ret;
}

int main(void)
{
    int a, n;
    scanf("%d", &a);
    int isFind = 0;
    for (int i = 2; i < 10000; i++) {
        n = a * i;
        if (isValid(n)) {
            printf("%d", n);
            isFind = 1;
            break;
        }
    }
    if (!isFind) {
        printf("-1");
    }

    return 0;
}