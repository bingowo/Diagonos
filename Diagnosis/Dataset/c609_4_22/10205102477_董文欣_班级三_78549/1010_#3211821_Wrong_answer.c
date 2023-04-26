#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    char ans[100];
    int cnt = 0;
    while (n) {
        int x = (n%r + abs(r)) % abs(r);
        if (x >= 10) ans[cnt] = x + 'A' - 10;
        else ans[cnt] = x + '0';
        cnt++;
        n -= x;
        n /= r;
    }
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%c",ans[i]);
    }
    return 0;
}
