#include <stdio.h>
int main()
{
    int T, cnt = 0;
    scanf("%d", &T);
    while (T--)
    {
        printf("case #%d:\n", cnt++);
        int N;
        scanf("%d", &N);
        printf("%d",N/5+N/25+N/125+N/625);
       /* int a[10000] = {1}, i, up, c, s, j;
        c = 1;
        for (i = 1; i <= N; i++)
        {
            up = 0;
            for (j = 0; j < c; j++)
            {
                s = a[j] * i + up;
                a[j] = s % 10;
                up = s / 10;
            }
            while (up)
            {
                a[c++] = up % 10;
                up /= 10;
            }
        }
        for (i = c - 1; i >= 0; i--)
        {
            printf("%d", a[i]);
        }
        printf("\n");*/

    }
    
    return 0;
}