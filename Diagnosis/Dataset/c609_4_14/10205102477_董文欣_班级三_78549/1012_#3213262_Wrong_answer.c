#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; i++) {
        char d[50];//八进制数
        scanf("%s",d);
        int len = strlen(d);
        double ans = 0.0;
        for (int j = len - 1; j >= 2; j--) {
            ans += d[j] - '0';
            ans *= 0.125;
        }

        //输出
        printf("case #%d:\n%f\n",i,ans);

    }
    return 0;
}
