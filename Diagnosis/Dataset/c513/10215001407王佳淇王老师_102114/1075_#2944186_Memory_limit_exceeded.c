#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int minPathSum(int **grid, int gridSize, int gridColSize) {
    int rows = gridSize, columns = gridColSize;
    if (rows == 0 || columns == 0) {
        return 0;
    }
    int dp[rows][columns];
    dp[0][0] = grid[0][0];
    for (int i = 1; i < rows; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < columns; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            dp[i][j] = fmin(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[rows - 1][columns - 1];
}
int main(){
	int m,n;
	scanf("&d %d",&m,&n);
	int **ar = (int**)malloc(sizeof(int*) * m); 
    for (int i = 0;i< m;i++)
    {
        ar[i] = (int*)malloc(sizeof(int) * n);
    }
    for (int i=0;i <m;i++)
    {for (int j=0;j<n;j++) scanf("%d ",&ar[i][j]);}
  int sum=minPathSum(ar,m,n);
	printf("%d\n",sum);
	return 0;


}
