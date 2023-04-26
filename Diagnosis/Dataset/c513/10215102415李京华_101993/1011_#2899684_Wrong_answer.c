#include <stdio.h>

void Solution(int n) {
    int Bin[32] = {0};
    int len = 0;    //二进制串位数
    while ( n ) {
        Bin[len++] = n & 1;
        n >>= 1;
    }

    int ans[32], cnt = 0;
    int i;
    long long a, b;
    a = b = 0;
    for (i = len - 1; i >= 0; i-- ){
        int r = Bin[i];
        int a1, b1;
        a1 = - a - b + r;
        b1 = a - b;
        a = a1;
        b = b1;
        // printf("a = %d, b = %d\n", a,b);
    }
    // printf("a = %d, b = %d\n", a,b);
    if (a == 0){    //没有实部
        if (b == 0)
            printf("0");
        else
            printf("%lldi", b);
    }else{
        printf("%lld", a);
        if (b != 0)
            if (b > 0){
                if (b > 1)
                    printf("+%lldi", b);
                else
                    printf("+i");
            }
            else
                printf("%lldi", b);
    }

    //输出

}

int main() {
    int n;
    scanf("%x", &n);
    Solution(n);
    return 0;
}