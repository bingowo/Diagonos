#include <stdio.h>

int main()
{
    int m, n;
    int num[1001] = {0};
    scanf("%d", &m);
    int a[m];
    for (int i = 0; i < m; i ++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &n);
    int b[n];
    for (int i = 0; i < n; i ++){
        scanf("%d", &b[i]);
        num[b[i]] ++;
    }
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < num[a[i]]; j ++){
            printf("%d ", a[i]);
        }
        num[a[i]] = 0;
    }
    for (int i = 0; i < 1001; i ++){
        for (int j = 0; j < num[i]; j ++){
            printf("%d ", i);
        }
        num[i] = 0; 
    }
    return 0;
}