#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void func(char *s)
{
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cnt = 0; cnt < T; ++cnt)
    {
        int res;
        char s[51];
        scanf("%s", &s);
        int slen = strlen(s) - 2;
        // printf("%d ", slen);
        char dec[200] = "0.";
        // dec[0] = '0';
        // dec[1] = '.';
        long long x, sum = 0;
        for (int i = 2; i < strlen(s); ++i)
        {
            x = (s[i] - '0') * pow(8, slen - i + 1);
            sum += x;
            // printf("%lld %lld\n", x, sum);
        }
        // printf("\n");
        for (int i = 0; i < 3 * slen; ++i)
        {
            sum = sum * 10;
            int j = sum / pow(8, slen);
            dec[2 + i] = j + '0'; // 依次将相应十进制小数的每一位存入字符串
            sum = sum % (long long)pow(8, slen);
            // printf("%lld ", sum);
        }

        dec[slen * 3 + 2] = '\0'; // 加终止符号，除零
        // printf("%s ", dec);
        int len = strlen(dec);
        for (int i = len - 1; i > 1; --i)
        {
            if (dec[i] == '0')
                dec[i] = '\0';
            else
                break;
        }
        printf("case #%d:\n%s\n", cnt, dec);
    }
    return 0;
}