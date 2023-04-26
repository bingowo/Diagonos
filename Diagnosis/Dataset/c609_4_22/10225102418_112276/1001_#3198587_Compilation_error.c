#include <stdio.h>
#include <stdlib.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int k =0;k<T,k++)
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
    int n = 0;
    while (t != 0)
    {
        t /= r;
        ++n;
    }
    int *f = (int *)malloc(sizeof(int) * n);
    while (temp != 0)
    {
        temp /= r;
        int i = temp % r;
        if (i > 9)
        {
            f[n - 1] = i + 55;
        }
        else
        {
            f[n - 1] = i + 48;
        }
        --n;
    }
    for (int p = 0; p < n; p++)
    {
        printf("%c", f[p]);
    }
    printf("\n");
    }
    return 0;
}