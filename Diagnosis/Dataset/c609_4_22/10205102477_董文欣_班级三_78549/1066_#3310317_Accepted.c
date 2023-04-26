#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ans[5051] = {0};
int main()
{
    int n, w[101] = {0};
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        cnt += w[i];
    }
    int state = pow(3, n);
    for (int i = 0; i < state; i++) {
        int tmp = i;
        int left = 0, right = 0;
        for (int j = 0; j < n; j++) {
            if (tmp % 3 == 0) left += w[j];
            else if (tmp % 3 == 1) right += w[j];
            tmp /= 3;
        }
        //printf("---left = %d, right = %d\n", left, right);
        if (left >= right) continue;
        ans[right - left] = 1;
    }

    for (int i = 1; i <= cnt; i++) {
        printf("%d", ans[i]);
    }
    return 0;
}
