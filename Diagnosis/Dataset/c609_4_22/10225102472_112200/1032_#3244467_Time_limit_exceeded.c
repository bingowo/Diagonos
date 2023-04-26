#include <stdio.h>

int main()
{
    char ch[55] = "\0";

    scanf("%s", ch);

    int len = 1, maxlen = 1;

    char *left = &ch[0];

    char *right = left + 1;

    while (*right != '\0')
    {
        if ((right - left) % 2 == 1)
        {
            if (*left != *right)
            {
                len++;
                right++;
            }

            else
            {
                if (maxlen < len)  maxlen = len;

                len = 1;

                left = right - 1;
            }
        }

        if ((right - left) % 2 == 0)
        {
            if (*left == *right)
            {
                len++;
                right++;
            }

            else
            {
                if (maxlen < len)  maxlen = len;

                len = 1;

                left = right - 1;
            }
        }
    }

    printf("%d\n", maxlen);

    return 0;
}
