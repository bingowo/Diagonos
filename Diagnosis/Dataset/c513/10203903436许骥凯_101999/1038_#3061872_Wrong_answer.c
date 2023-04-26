#include<stdio.h>


#define min(x, y) ((x) < (y)? (x): (y))
#define MAX_LEN 200

void Print(int (*arr)[MAX_LEN], int n, int m){
    for (int i = 0; i != n; ++i){
        for (int j = 0; j != m; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void Input(int (*arr)[MAX_LEN], int n, int m){
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            scanf("%d", &arr[i][j]);
}

int sum(int (*arr)[MAX_LEN], int x, int y, int len){
    int res = 0;
    for (int i = 0; i <= len; ++i)
        for (int j = 0; j <= len - i; ++j)
            res += arr[x + i][y + j];
    return res;
}

int cal_cnt(int (*arr)[MAX_LEN], int n, int m, int k){
    int cnt = 0;
    for (int len = 1; len != min(n, m); ++len){
        for (int x = 0; x + len < n; ++x){
            for (int y = 0; y + len < m; ++y){
                if (sum(arr, x, y, len) >= k) ++cnt;
            }   
        }
    }
    return cnt;
}

void swap(int *n, int *m){
    int temp = *n;
    *n = *m;
    *m = temp;
}

void rotate(int (*arr)[MAX_LEN], int *n, int *m){
    int temp[MAX_LEN][MAX_LEN];
    for (int i = 0; i != *n; ++i)
        for (int j = 0; j != *m; ++j)
            temp[j][*n - 1 - i] = arr[i][j];
    swap(n, m);
    for (int i = 0; i != *n; ++i)
        for (int j = 0; j != *m; ++j)
            arr[i][j] = temp[i][j];
}

int cal(int (*arr)[MAX_LEN], int n, int m, int k){
    int cnt = cal_cnt(arr, n, m, k);
    Print(arr, n, m);
    for (int i = 0; i != 3; ++i){
        rotate(arr, &n, &m);
        Print(arr, n, m);
        cnt += cal_cnt(arr, n, m, k);
    }
    return cnt;
}


int main(){
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    int matrix[MAX_LEN][MAX_LEN];
    Input(matrix, n, m);
    printf("%d\n", cal(matrix, n, m, k));
    return 0;
}