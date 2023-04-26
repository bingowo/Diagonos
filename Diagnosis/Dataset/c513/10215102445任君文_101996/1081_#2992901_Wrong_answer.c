#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int a, n, c, t;
    int num[110] = { 0 };
    int i, j, k, T, m;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d%d", &a, &n);
        num[0] = a;
        m = 1;
        c = 0;
        t = 0;
        for (j = 0; j < n; j++)
        {
            c = 0;
            for (k = 0; k < m; k++)
            {
                t = num[k] * a + c;
                c = t / 10;
                num[k] = t % 10;
            }
            if (c != 0)
            {
                num[m] = c;
                m++;
            }

        }
        printf("case #%d:\n", i);
        if (n == 0)
            printf("%d\n", 1);
        else if (n == 2)
            printf("%d\n", a);
        else
        {
            for (j = m-1; j >= 0; j--)
            {
                printf("%d", num[j]);
            }
            printf("\n");
        }
    }
    return 0;
}