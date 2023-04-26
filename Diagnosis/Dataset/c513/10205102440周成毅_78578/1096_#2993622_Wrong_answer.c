#include <stdio.h>
#include <stdlib.h>

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
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n, qi[10000], ho[10000],flag=1;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
            scanf("%d %d", &qi[j], &ho[j]);
        qsort(qi, n, sizeof(int), cmp);
        qsort(ho, n, sizeof(int), cmp);
        for(int j=0;j<n;j++){
            if(isin(ho,n,qi[j])){
                printf("Poor dxw!\n");
                flag=0;
                break;
            }
        }
        if(flag)
            printf("Lucky dxw!\n");
    }
    return 0;
}
