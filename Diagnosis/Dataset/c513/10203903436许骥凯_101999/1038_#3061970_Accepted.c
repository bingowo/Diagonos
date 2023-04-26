#include<stdio.h>

#define MAX_LEN 200

void Input(int (*arr)[MAX_LEN + 1], int n, int m){
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &arr[i][j]);
}

int cal_cnt(int (*arr)[MAX_LEN + 1], int (*table)[MAX_LEN + 1], int x, int y, int n, int m, int k){
    int cnt = 0;
    int res = arr[x][y];
    for (int len = 1; x + len <= n && y + len <= m; ++len){
        res += table[x + len][y + len] - table[x - 1][y + len];
        if (res >= k) ++cnt;
    }
    res = arr[x][y];
    for (int len = 1; x + len <= n && y - len >= 1; ++len){
        res += table[x + len][y - len] - table[x - 1][y - len];
        if (res >= k) ++cnt;
    }
    res = arr[x][y];
    for (int len = 1; x - len >= 1 && y + len <= m; ++len){
        res += table[x][y + len] - table[x - len - 1][y + len];
        if (res >= k) ++ cnt;
    }
    res = arr[x][y];
    for (int len = 1; x - len >= 1 && y - len >= 1; ++len){
        res += table[x][y - len] - table[x - len - 1][y - len];
        if (res >= k) ++cnt;
    }
    return cnt;
}


int cal(int (*arr)[MAX_LEN + 1], int (*table)[MAX_LEN + 1], int n, int m, int k){
    int cnt = 0;
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= m; ++y)
            cnt += cal_cnt(arr, table, x, y, n, m, k);
    return cnt;
}

void Init(int (*arr)[MAX_LEN+1]){
    for (int i = 1; i != MAX_LEN + 1; ++i)
        arr[0][i] = 0;
}

void cal_col_sum(int (*dest)[MAX_LEN + 1], int (*source)[MAX_LEN + 1], int n, int m){
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dest[i][j] = dest[i - 1][j] + source[i][j];
}



int main(){
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    int matrix[MAX_LEN + 1][MAX_LEN + 1], col_sum[MAX_LEN + 1][MAX_LEN + 1];
    Init(col_sum);
    Input(matrix, n, m);
    cal_col_sum(col_sum, matrix, n, m);
    printf("%d\n", cal(matrix, col_sum, n, m, k));
    return 0;
}