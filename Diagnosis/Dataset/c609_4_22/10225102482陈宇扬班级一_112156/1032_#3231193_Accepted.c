#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[100] = {0};
    int cnt = 1, max = 1;
    while ((scanf("%s", s)) != EOF);

    int len = strlen(s);
    for (int j = 0; j < len - 1; j++)
    {
        if (s[j] != s[j + 1])
            cnt++;
        else
        {
            if (cnt > max)
                max = cnt;
            cnt = 1;
        }
    }
    if (cnt > max)
        max = cnt;
    cnt = 1;
    printf("%d\n", max);
    return 0;
}
