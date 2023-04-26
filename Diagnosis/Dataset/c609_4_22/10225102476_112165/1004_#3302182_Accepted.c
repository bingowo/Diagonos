#include <stdio.h>

int main()

{

    char table[17] = "0123456789ABCDEF";

    int n, m;

    char s[33];

    scanf("%d", &n);

    scanf("%s", s, 33);

    scanf("%d", &m);

    int num = 0;

    for (int i = 0;s[i] != '\0';i++)
    {

        if (s[i] >= '0' && s[i] <= '9')

            num = num * n + s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'z')

            num = num * n + s[i] - 'a' + 10;
        else

            num = num * n + s[i] - 'A' + 10;

    }

    int digit[32], cnt = 0;

    do {

        digit[cnt++] = num % m;

        num = num / m;

    } while (num != 0);

    for (int i = cnt - 1;i >= 0;i--)

        printf("%c", table[digit[i]]);

    printf("\n");

    return 0;

}