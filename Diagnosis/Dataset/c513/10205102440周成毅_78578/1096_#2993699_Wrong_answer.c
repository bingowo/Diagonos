#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int isin(int arr[], int len, int value) {
    int low = 0, high = len - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (value > arr[mid]) {
            low = mid + 1;
        } else if (value < arr[mid]) {
            high = mid - 1;
        } else {
            return 1;
        }
    }
    return 0;
}

int main() {
    int T;
    int arr[10000][2];
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
            arr[b][0]++;
        }
        int Q = 1;
        for(int j = 0; j <= max; j++)
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
