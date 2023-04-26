#include <stdio.h>
int solve(int time, int floor, int n, int p)
{
    if (time == 0)
        if (floor == p)
        {
            return 1;
        }
        else
            return 0;
    if (floor == 1)
        return solve(time - 1, 2, n, p);
    else if (floor == n)
        return solve(time - 1, n - 1, n, p);
    else
    {
        return solve(time - 1, floor + 1, n, p) + solve(time - 1, floor - 1, n, p);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, p, m, t;
        scanf("%d%d%d%d", &n, &p, &m, &t);
        int res = solve(m, p, n, t);
        printf("%d\n", res);
    }
}