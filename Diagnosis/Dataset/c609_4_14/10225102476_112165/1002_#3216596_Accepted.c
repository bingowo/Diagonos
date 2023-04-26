#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int i = 0;
    while (i < a) {
        int t;
        scanf("%d", &t);
        int s[1000];
        int m = 0;
        while (t)
        {
            s[m] = t % 2;
            t = t / 2;
            m++;
        }
        int c = 1, d = 0;
        int r = 1;
        while (d < m-1)
        {
            if (s[d] != s[d + 1])
            {
                c++;
                if (c > r)
                    r = c;
            }
            else
            {
                if (c > r)
                    r = c;
                c = 1;
            }
            d++;
        }

        printf("case #");
        printf("%d:\n", i);
        printf("%d\n", r);
        i++;
    }
    return 0;
}