#include <stdio.h>
#include <string.h>
int main()
{
    char s[100] = {0};
    int cnt = 0, max = 1;
    while ((scanf("%s", s)) != EOF)
        ;
    int size = strlen(s);
    for (int j = 0; j < size; j++)
    {
        if (j == size - 1)
            break;
        if (s[j] != s[j + 1])
            cnt++;
        else if (s[j] == s[j + 1])
            cnt = 1;
        if (cnt > max)
            max = cnt;
    }
    printf("%d\n", max);
    return 0;
}