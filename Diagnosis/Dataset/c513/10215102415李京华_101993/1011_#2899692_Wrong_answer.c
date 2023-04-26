#include <stdio.h>

void Solution(long long n) {
    int Bin[64] = {0};
    int len = 0;
    while ( n ) {
        Bin[len++] = n & 1;
        n >>= 1;
    }

    int ans[64], cnt = 0;
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
    }
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
    long long n;
    scanf("%llx", &n);
    Solution(n);
    return 0;
}