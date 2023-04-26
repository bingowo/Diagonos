#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int T, i, j,ans[4], x, len,r,g,b,y,z;
    char s[101];
    scanf("%d", &T);
    for (x = 0;x < T;x++)
    {
        printf("case #%d:\n", x);
        scanf("%s", s);
        len = strlen(s);
        memset(ans, 0, sizeof(ans));
        i = 0;
        while (strchr(s, '!') != NULL)
        {
            r = g = b = y = z = 0;
            for (j = i;j < i + 4;j++)
            {
                if (s[j] == 'R') r++;
                else if (s[j] == 'G') g++;
                else if (s[j] == 'B') b++;
                else if (s[j] == 'Y') y++;
                else z++;
            }
            if (z == 1)
            {
                if (r == 0)
                {
                    ans[0]++;s[i] = 'R';
                }
                else if (g == 0)
                {
                    ans[1]++;s[i] = 'G';
                }
                else if (b == 0)
                {
                    ans[2]++;s[i] = 'B';
                }
                else
                {
                    ans[3]++;s[i] = 'Y';
                }
                i = 0;
            }
            else
                i++;
        }
        for (i = 0;i < 4;i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
