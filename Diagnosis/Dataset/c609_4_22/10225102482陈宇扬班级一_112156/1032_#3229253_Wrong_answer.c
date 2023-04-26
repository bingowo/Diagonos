#include <stdio.h>
#include <string.h>
int main()
{
    char s[51] = {0};
    int cnt = 0, max = 1;
    while ((scanf("%s", s)) != EOF)
        ;
    int size = strlen(s);
    for (int j = 0; j < size; j++)
    {
        if (size == 1)
        {
            max = 1;
            break;
        }
        else if (size == 2)
        {
            if (s[0] != s[1])
            {
                max = 2;
            }
            else if (s[0] == s[1])
            {
                max = 1;
            }
        }
        else
        {
            if (s[j] != s[j + 1])
                cnt++;
            else if (s[j] == s[j + 1])
                cnt = 1;
            if (cnt > max)
                max = cnt;
        }
    }
    printf("%d\n", max);
    return 0;
}