#include <stdio.h>
#include <string.h>

int main() {
    int T;
    int arr[10001][2];
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        memset(arr, 0, sizeof(arr));
        int n, a, b, max = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d %d", &a, &b);
            if (a > max)
                max=a;
            if(b>max)
                max=b;
            if(a==b)
                continue;
            arr[a][0]++;
            arr[b][1]++;
        }
        int Q = 1;
        for(int j = 1; j <= max; j++)
        {
            if((arr[j][0] >= 1 && arr[j][1] >= 1) || arr[j][0] >= 2)
                Q = 0;
        }
        if(Q)
            printf("Lucky dxw!\n");
        else
            printf("Poor dxw!\n");
    }
    return 0;
}
