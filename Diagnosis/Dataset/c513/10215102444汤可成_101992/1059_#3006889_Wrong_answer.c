#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int GCD(int a, int b)
{
    b = b == 0 ? a : GCD(b, a%b);
    return b;
}

int main()
{
    int n = 0;
    int s = 0;
    int fz = 0;
    int fm = 0;
    scanf("%d %d", &n, &s);
    int a[1001] = {0};
    for(int i = 0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, cmp);
    a[n] = 100009;
    for(int i = 1; i<=n; i++)
    {
        int c = (a[i] - a[i-1]) * i;
        if(s>c)
        {
            s -= c;
        }
        else
        {
            int z = a[i-1]+s/i;
            int g = GCD(s%i, i);
            fz = (s%i)/g;
            fm = i/g;
            if(z == 0 && fz > 0)
            {
                printf("%d/%d", fz, fm);
            }
            else
            {
                printf("%d", z);
                if(fz>0)
                {
                    printf("+%d/%d", fz, fm);
                }
            }
        }
    }
    return 0;
}
