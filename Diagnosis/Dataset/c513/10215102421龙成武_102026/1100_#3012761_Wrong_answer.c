#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int q, i, j,len, k1, k2, c1, c2, dx = 0, dy = 0, x, y;
    char s[101];
    scanf("%s", s);
    len = strlen(s);
    for (i = 0;i < len;i++)
    {
        if (s[i] == 'U') dy++;
        else if (s[i] == 'D') dy--;
        else if (s[i] == 'L') dx--;
        else if (s[i] == 'R') dx++;
    }
    scanf("%d", &q);
    for (i = 0;i < q;i++)
    {
        scanf("%d %d", &x, &y);
        k1 = k2 = 0;
        c1 = c2 = 0;
        if (dx != 0)
        {
            k1 = x / dx;
            c1 = x % dx;
        }
        if (dy != 0)
        {
            k2 = y / dy;
            c2 = y % dy;
        }
        if (k1 != k2 && (k1 != 0 && k2 != 0))
        {
            printf("No\n");break;
        }
        x = y = 0;
        j = 0;
        while (!(x == c1 && y == c2) && j < len)
        {
            if (s[j] == 'U') y++;
            else if (s[j] == 'D') y--;
            else if (s[j] == 'L') x--;
            else if (s[j] == 'R') x++;
            j++;
        }
        if (j == len)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
