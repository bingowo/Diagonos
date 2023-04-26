#include <stdio.h>

int main()
{
    char ch[55] = "\0";

    scanf("%s", ch);

    int len = 1, maxlen = 1;

    for (int i = 1; ch[i] != '\0'; i++)
    {
        if (maxlen < len)  maxlen = len;

        if (ch[i] != ch[i - 1])  len++;

        else  len = 1;
        
        if (maxlen < len)  maxlen = len;
    }

    printf ("%d", maxlen);

    return 0;
}
