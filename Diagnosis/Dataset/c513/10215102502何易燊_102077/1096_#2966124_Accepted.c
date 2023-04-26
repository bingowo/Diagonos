#include <stdio.h>

int main()
{
    int T; scanf("%d",&T);
    while (T--)
    {
        int a[101] = {}, b[101] = {};
        int judge = 1, state = 1;
        int n; scanf("%d ",&n);
        int x,y,nx=0,ny=0;
        int table[10100] = {};
        while (n--)
        {
            scanf("%d %d",&x,&y);
            if (table[100*x+y]) continue;
            else table[100*x+y]++;
            if (a[x]||a[y]||b[x]) judge = 0;
            a[x]++, b[y]++;
        }
        if (judge) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}