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
        int numbers = 0;
        char ans[152] = {'0'};
        for (int j = len - 1; j >= 2; j--) {
            int digit = d[j] - '0';
            int k;
            for (k = 0; k < numbers || digit; k++) {
                int tmp = 10 * digit + (k < numbers ? ans[k] : 0);
                ans[k] = tmp / 8;
                digit = tmp % 8;
            }
            numbers = k;
        }
        //输出
        printf("case #%d:\n0.",i);
        for (int j = 0; j < numbers; j++) printf("%d",ans[j]);
        printf("\n");
    }
    return 0;
}
