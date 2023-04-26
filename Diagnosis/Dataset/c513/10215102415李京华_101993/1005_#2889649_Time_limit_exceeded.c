#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Solution(char *s) {
    char ans[200];
    int i, cnt = 0;//cnt:十进制小数位数
    for (i = strlen(s) - 1; i > 1; i++) {
        int n = s[i] - '0';
        int j = 0;
        int temp;
        do {
            if (j < cnt)
                temp = n * 10 + ans[j] - '0';
            else
                temp = n * 10;
            ans[j++] = temp / 8 + '0';
            n = temp % 8;
        } while (n || j < cnt);

        cnt = j;        
    }
    ans[cnt] = '\0';
    printf("0.%s\n", ans);
}

int main()
{
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; t++){
        char s[55];
        scanf("%s", s);
        printf("case #%d:\n",t);
        Solution(s);
    }
    return 0;
}