#include <stdio.h>

int dp[200][200];

int min(int x, int y) {
    return x >= y ? y : x;
}

int main() {
    int M, N;
    int matrix[200][200];
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &matrix[i][j]);
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < M; i++)
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    for (int i = 1; i < N; i++)
        dp[0][i] = dp[0][i - 1] + matrix[0][i];
    for (int i = 1; i < M; i++)
        for (int j = 1; j < N; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];

    int pos_x = M-1, pos_y = N-1, len = 0;
    char path[401];
    while (pos_x >=0 && pos_y >=0) {
        if (pos_x == 0 && pos_y==0) {
            break;
        } else if (pos_x == 0) {
            path[len++] = 'R';
            pos_y--;
        } else if(pos_y==0){
            path[len++] = 'D';
            pos_x--;
        } else{
            if(dp[pos_x-1][pos_y]<dp[pos_x][pos_y-1]){
                path[len++]='D';
                pos_x--;
            } else{
                path[len++]='R';
                pos_y--;
            }
        }
    }
    printf("%d\n", dp[M-1][N-1]);
    for (int i = len - 1; i >= 0; i--)
        printf("%c", path[i]);
    printf("\n");
    return 0;
}
