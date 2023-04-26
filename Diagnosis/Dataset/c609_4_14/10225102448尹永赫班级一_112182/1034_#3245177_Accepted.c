#include <stdio.h>

int main()
{
    char str[100000] = {'\0'};
    char digit[100000] = {'\0'};
    char *ps = str;
    int j = 0;
    int temp = 0;
    gets(str);
    while (*ps != '\0')
    {
        if (*ps == '0' && *(ps + 1) == 'x')
        {
            ps = ps + 2;
            int i = 0;
            while (*ps >= '0' && *ps <= '9' || *ps >= 'A' && *ps <= 'F' || *ps >= 'a' && *ps <= 'f')
            {
                digit[j] = *ps;
                ps++;
                j++;
                i++;
            }
            if (i != 0)
            {
                j -= i;
                unsigned int num = 0;
                while (digit[j] != '\0')
                {
                    if (digit[j] >= '0' && digit[j] <= '9')
                        num = num * 16 + digit[j] - '0';
                    else if (digit[j] >= 'A' && digit[j] <= 'F')
                        num = num * 16 + digit[j] - 'A' + 10;
                    else if (digit[j] >= 'a' && digit[j] <= 'f')
                        num = num * 16 + digit[j] - 'a' + 10;
                    j++;
                }
                temp++;
                printf("%u ", num);
            }
        }
        ps++;
    }
    if (temp == 0)
        printf("-1");
    return 0;
}