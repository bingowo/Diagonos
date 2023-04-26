#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    int cnt = 0, max = 1;
    while ((scanf("%s", s)) != EOF)
        ;
    for (int j = 0; j <= strlen(s); j++)
    {
        if (s[j] != s[j + 1])
            cnt++;
        else if (s[j] == s[j + 1])
        {
            cnt = 1;
            continue;
        }
        if (cnt > max)
            max = cnt;
    }
    printf("%d\n", max);
    return 0;
}