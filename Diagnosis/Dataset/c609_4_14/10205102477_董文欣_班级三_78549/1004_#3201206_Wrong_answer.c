#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int A,B;
    char n[32] = {'0'};
    scanf("%d %s %d",&A,n,&B);
    int len = strlen(n);
    int ans = 0;
    //将A进制转换为十进制
    for (int i = 0; i < len; i++) {
        if (n[i] >= '0' && n[i] <= '9') {ans = ans * A + n[i] - '0';}
        if (n[i] >= 'A' && n[i] <= 'Z') {ans = ans * A + n[i] - 'A' + 10;}
        if (n[i] >= 'a' && n[i] <= 'z') {ans = ans * A + n[i] - 'a' + 10;}
    }
    //将十进制转换为B进制
    char res[32] = {'0'};
    int i = 0;
    while (ans) {
        if (ans % B >= 10) {res[i++] = ans % B - 10 + 'A';}
        else res[i++] = ans % B + '0';
        ans /= B;
    }

    //输出
    while (i--) {
        printf("%c",res[i]);
    }
    printf("\n");
    return 0;
}
