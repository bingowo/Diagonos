#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("0x%s", s);
    int Bin[100] = {0};
    int len = 0;

    int i;
    for (i = strlen(s) - 1; i >= 0; i--){
        int res;
        if (s[i] >= 0 && s[i] <= '0')
            res = s[i] - '0';
        else
            res = s[i] - 'A' + 10;
        int cnt = 0;
        while ( cnt < 4){
            cnt++;
            Bin[len++] = res & 1;
            res >>= 1;
        }
    }

    int ans[100], cnt = 0;
    long long a, b;
    a = b = 0;
    for (i = len - 1; i >= 0; i-- ){
        int r = Bin[i];
        int a1, b1;
        a1 = - a - b + r;
        b1 = a - b;
        a = a1;
        b = b1;
        printf("a = %d, b = %d\n", a, b);
    }

    //输出
    if (a == 0){    //没有实部
        if (b == 0)
            printf("0");
        else
            if (b > 0){
                if (b > 1)
                    printf("+%lldi", b);
                else
                    printf("i");
            }
            else{
                if (b == -1)
                    printf("-i");
                else
                    printf("%lldi", b);
            }
    }
    else{
        printf("%lld", a);
        if (b != 0)
            if (b > 0){
                if (b > 1)
                    printf("+%lldi", b);
                else
                    printf("+i");
            }
            else{
                if (b == -1)
                    printf("-i");
                else
                    printf("%lldi", b);
            }
                
    }

    
    return 0;
}
