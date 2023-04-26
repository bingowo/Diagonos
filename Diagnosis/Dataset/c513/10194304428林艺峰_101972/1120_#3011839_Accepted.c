#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int w[20][20];
int total(int x1, int y1, int x2, int y2){
	int i, j, sum = 0;
	for(i = x1; i <= x2; ++i){
		for(j = y1; j <= y2; ++j){
			if(w[i][j])	sum += 1;
		}
	}
	return sum;
}
int main(){
	int t, i, j, count = 0, r, c, n, k, x1, y1, x2, y2, x, y;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d%d%d%d", &r, &c, &n, &k);
		memset(w, 0, sizeof(w));
		count = 0;
		for(j = 0; j < n; ++j){
			scanf("%d%d", &x, &y);
			w[x][y] = 1;
		}
		for(x1 = 1; x1 <= r; ++x1){
			for(y1 = 1; y1 <= c; ++y1){
				for(x2 = x1; x2 <= r; ++x2){
					for(y2 = y1; y2 <= c; ++y2){
						if(total(x1, y1, x2, y2) >= k) count += 1;
					}
				}
			}
		}
		printf("case #%d:\n%d\n", i, count);
	}

}