#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);
    int i = 0;
    while(T--) {
        char s[61]; //字符串
        scanf("%s",s);
        int a[128];
        for (int i = 0; i < 128; i++) a[i] = -1; //第一次出现的为-1
        char *p = s; //表示指向字符串的第一个数
        int digit = 0, n = 1;
        a[*p] = 1;
        while(*++p) {
            if (a[*p] == -1)
            {
                a[*p] = digit;
                digit = digit ? digit + 1 : 2;
                n = n + 1;
            }
        }
        if (n < 2) n = 2; //最小为二进制

        //输出
        printf("case #%d:\n",i++);
        long long ans = 0;
        p = s;
        while (*p) {ans = ans * n + a[*p++];}
        printf("%lld\n",ans);
    }
    return 0;
}
