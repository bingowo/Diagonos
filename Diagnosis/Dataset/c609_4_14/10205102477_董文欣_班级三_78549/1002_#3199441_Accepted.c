#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; i++) {
        int n;//一个十进制表示的正整数 n
        scanf("%d",&n);
        int a[32] = {0};
        int j = 0;
        int ans = 1,max = 1;
        while (n)
        {
            a[++j] = n%2;
            n = n / 2;
        }
        while (j > 1) {
            if (a[j] != a[j-1]) ans++;
            else ans = 1;
            j = j - 1;
            max = ans > max ? ans : max;
        }

        //输出
        printf("case #%d:\n%d\n",i,max);

    }
    return 0;
}
