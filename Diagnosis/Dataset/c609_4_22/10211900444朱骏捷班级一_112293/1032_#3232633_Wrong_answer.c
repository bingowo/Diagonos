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
        // printf("%d %d\n", (int)s[i],(int)s[i + 1]);
        if (s[i] != s[i + 1])
            cnt++;
            // continue;
        else
        {
            /*if(max < cnt)
                max = cnt;*/
            cnt = 1;
        }
        if(max < cnt)
            max = cnt;
    }
    printf("%d", max);
    return 0;
}
