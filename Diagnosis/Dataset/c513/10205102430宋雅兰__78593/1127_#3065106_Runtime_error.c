#include <stdio.h>
#include <string.h>
int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}
int main()
{
    int n;
    scanf("%d", &n);
    char a[100][10000];
    int fz = 0, fm = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
        int l = strlen(a[i]);
        int flag = 0;
        for (int j = 0; j < l; j++)
        {
            if (a[i][j] = '/')
                flag = 1;
            if (flag)
            {
                fm = fm * 10 + a[i][j] - '0';
            }
            else
                fz = fz * 10 + a[i][j] - '0';
        }
    }
    int t = gcd(fz, fm);
    printf("%d/%d", fz/t, fm/t);
    return 0;
}