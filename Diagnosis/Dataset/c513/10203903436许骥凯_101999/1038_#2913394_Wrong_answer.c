#include<stdio.h>
#include<stdlib.h>

int** transmit(int **t, int *n, int *m){
    int nt = *m, mt = *n;
    int **temp = (int**)malloc(sizeof(int*) * (nt+1));
    for (int i = 0; i <= nt; i++) temp[i] = (int*)malloc(sizeof(int) * (mt+1));
    for (int i = 0; i <= *n; i++){
        for (int j = 0; j <= *m; j++)
            temp[nt-j][i] = t[i][j];
        free(t[i]);
    }
    free(t);
    *n = nt, *m = mt;
    return temp;
}

int cal(int *matrix[], int n, int m, int k){
    int cnt = 0;
    for (int i = 0; i != 3; i++){
        for (int x = 0; x != n; x++){
            for (int y = 0; y != m; y++){
                int ps = matrix[0][0];
                for (int r = 1; (r + x <= n) && (r + y <= m); r++){
                    int temp = 0;
                    for (int t = 0; t <= r; t++)
                        temp += matrix[x+t][y+r-t];
                    ps += temp;
                    if (ps >= k){cnt += 1 + ((n-x) > (m-y)? (m-y-r): (n-x-r)); break;}
                }
            }
        }
        matrix = transmit(matrix, &n, &m);
    }
    for (int i = 0; i != m; i++)
        free(matrix[i]);
    free(matrix);
    return cnt;
}

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int **a = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i != n; i++)
        a[i] = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i != n; i++)
        for (int j = 0; j != m; j++)
            scanf("%d", &a[i][j]);
 
    int cnt = cal(a, n - 1, m - 1, k);
    printf("%d\n", cnt);
    return 0;
}