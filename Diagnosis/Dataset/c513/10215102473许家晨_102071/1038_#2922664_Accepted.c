/*
Created by Shizumu on 2022/2/28.
	这个题目考虑了使用前缀和的方法，具体已经体现在了变量名称上
	简单来讲就是：不去计算三角形每一个方格而是用这些方格去拼接裁剪一个三角形。 
*/
#include <stdio.h> 

typedef long long int lli;
typedef struct{
	lli SumOfColumn;
	lli SumOfMatrix;
}Block;

int main(void)
{
	int n, m, k;
	lli temp, cnt = 0;
	scanf("%d %d %d", &n, &m, &k);
	Block in[n][m];
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			scanf("%lld", &temp);
			if(i == 0){
				in[i][j].SumOfColumn = temp;
			}else{
				in[i][j].SumOfColumn = temp + in[i - 1][j].SumOfColumn;
			}
			if(i == 0 && j == 0){
				in[i][j].SumOfMatrix = temp;
			}else if(i == 0){
				in[i][j].SumOfMatrix = in[i][j - 1].SumOfMatrix + temp;
			}else if(j == 0){
				in[i][j].SumOfMatrix = in[i - 1][j].SumOfMatrix + temp;
			}else{
				in[i][j].SumOfMatrix = in[i - 1][j].SumOfMatrix + in[i][j - 1].SumOfMatrix - in[i - 1][j - 1].SumOfMatrix + temp;
			}
		}
	}
	lli area, LargeRect;
	for(int i = 0 ;i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			for(int t = 0; i + t < n && j + t < m; t ++){
				area = LargeRect = 0;
				for(int r = i + t, c = j; r >= i &&  c <= j + t; r --, c ++){
					if(i == 0){
						area += in[r][c].SumOfColumn;
					}else{
						area += (in[r][c].SumOfColumn - in[i - 1][c].SumOfColumn);
					}				
				}
				if(area >= k && t != 0){ cnt ++;}
				if(i + t < n - 1 && j + t < m - 1){
					if(i == 0 && j == 0){
						LargeRect = in[i + t + 1][j + t + 1].SumOfMatrix;
					}else if(i == 0){
						LargeRect = in[i + t + 1][j + t + 1].SumOfMatrix - in[i + t + 1][j - 1].SumOfMatrix;
					}else if(j == 0){
						LargeRect = in[i + t + 1][j + t + 1].SumOfMatrix - in[i - 1][j + t + 1].SumOfMatrix;
					}else{
						LargeRect = in[i + t + 1][j + t + 1].SumOfMatrix - in[i + t + 1][j - 1].SumOfMatrix - in[i - 1][j + t + 1].SumOfMatrix + in[i - 1][j - 1].SumOfMatrix;
					}
					if(LargeRect - area >= k){ cnt ++;}
				}
			}
			
			for(int t = 0; i + t < n && j - t >= 0; t ++){
				area = LargeRect = 0;
				for(int r = i + t, c = j; r >= i &&  c >= j - t; r --, c --){
					if(i == 0){
						area += in[r][c].SumOfColumn;
					}else{
						area += (in[r][c].SumOfColumn - in[i - 1][c].SumOfColumn);
					}				
				}
				if(area >= k && t != 0){ cnt ++;}
				if(i + t < n - 1 && j - t > 0){
					if(i == 0 && j - t - 1 == 0){
						LargeRect = in[i + t + 1][j].SumOfMatrix;
					}else if(i == 0){
						LargeRect = in[i + t + 1][j].SumOfMatrix - in[i + t + 1][j - t - 2].SumOfMatrix;
					}else if(j - t - 1 == 0){
						LargeRect = in[i + t + 1][j].SumOfMatrix - in[i - 1][j].SumOfMatrix;
					}else{
						LargeRect = in[i + t + 1][j].SumOfMatrix - in[i + t + 1][j - t - 2].SumOfMatrix - in[i - 1][j].SumOfMatrix + in[i - 1][j - t - 2].SumOfMatrix;
					}
					if(LargeRect - area >= k){ cnt ++;}							
				}
			}
		}
	}
	
	printf("%llu", cnt);
	
	return 0;
}