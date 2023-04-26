#include <stdio.h>
#include <string.h>
#include <math.h>
#define FIN freopen("input.txt", "r", stdin);
// const int MX = 1e4;
int main()
{
#ifdef __LOCAL
    FIN;
#endif
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int xy = (x ^ y);
        int ans = 0;
        while(xy)
        {
            xy &= xy - 1;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}