#include <stdio.h>
#include <stdlib.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int k = 0;k<T;k++)
    {
    int t, r, temp;
    scanf("%d %d", &t, &r);
    if (t >= 0)
    {
        temp = t;
    }
    else
    {
        temp = -t;
        printf("-");
    }
    int ss[100];
    int n = 0;
    while (temp != 0)
    {
        temp /= r;
        int i = temp % r;
        if (i > 9)
        {
            f[n++] = i + 55;
        }
        else
        {
            f[n++] = i + 48;
        }
    }
    for (int p = 0; p < n; p++)
    {
        printf("%c", (char)f[n-p]);
    }
    printf("\n");
    }
    return 0;
}

