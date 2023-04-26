#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T; scanf("%d",&T);
    while (T--)
    {
        int a[101] = {}, b[101] = {};
        int judge = 1, state = 1;
        int n; scanf("%d ",&n);
        int x,y;
        while (n--)
        {
            scanf("%d %d",&x,&y);
            if (a[x]&&b[y]&&a[x]==b[y]) ;
            else if ((a[x]||a[y]||b[x])&&state) judge = 0, state = 0;
            a[x]++; b[y]++;
        }
        if (judge) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    system("pause");
    return 0;
}