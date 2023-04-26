#include <stdio.h>
#include <stdlib.h>
int a[210][210];
int f[210][210];
char road[1100];
int min(int x, int y){
	if(x < y)	return x;
	else	return y;
}
int main(){
	int m, n, i, j, len;
	scanf("%d%d", &m, &n);
	for(i = 1; i <= m; ++i){
		for(j = 1; j <= n; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	for(i = 1; i <= m; ++i)	f[i][1] = f[i-1][1] + a[i][1];
	for(i = 1; i <= n; ++i)	f[1][i] = f[1][i-1] + a[1][i];
	for(i = 1; i <= m; ++i)	f[i][0] = 99999999;
	for(i = 1; i <= n; ++i)	f[0][i] = 99999999;
	for(i = 2; i <= m; ++i){
		for(j = 2; j <= n; ++j){
			f[i][j] = min(f[i-1][j], f[i][j-1]) + a[i][j];
		}
	}
	printf("%d\n",f[m][n]);
	i = m; j = n; len = 0;
	while(!(i == 1 && j == 1)){
		if(f[i-1][j] > f[i][j-1]){
			road[len++] = 'R';
			j -= 1;
		}
		else{
			road[len++] = 'D';
			i -= 1;
		}
	}
	for(i = len - 1; i >= 0; --i)	printf("%c", road[i]); 
	return 0;
}