#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
    int T;
    scanf("%d", &T);
    for (int cnt = 0; cnt < T; ++cnt)
    {
        int res;
        char s[51];
        scanf("%s", &s);
        int dec[100000];
        int j, k, t = 0, x = 0;
        for (int i = strlen(s) - 1; i > 1; i--)
        {
            x = s[i] - '0';
            k = 0, j = 0;
            while (j < t || x)
            {
                x = x * 10 + dec[j++];
                dec[k++] = x / 8;
                x = x % 8;
            }
            t = k;
        }
        printf("case #%d:\n", cnt);
        printf("0.");
        for (int i = 0; i < t; i++)
            printf("%d", dec[i]);
    }
    return 0;
}