#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[60];
    scanf("%s", s);
    int len = strlen(s);
    int cnt = 1, max = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if (s[i] != s[i + 1])
            cnt++;
        else
        {
            if(max < cnt)
                max = cnt;
            cnt = 1;
        }
    }
    printf("%d", max);
    return 0;
}
