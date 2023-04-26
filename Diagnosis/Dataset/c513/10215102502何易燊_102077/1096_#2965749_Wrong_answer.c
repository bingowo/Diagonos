#include <stdio.h>

int main()
{
    int T; scanf("%d",&T);
    while (T--)
    {
        int a[101] = {}, b[101] = {};
        int judge = 1;
        int n; scanf("%d",&n);
        int x,y;
        while (n--)
        {
            scanf("%d %d",&x,&y);
            if (a[y]||b[x]) judge = 0;
            a[x]++; b[y]++;
        }
        if (judge) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}