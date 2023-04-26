#include <stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int N, M, K, i, j, ul = 0, ans = 0;
    scanf("%d%d%d", &N, &M, &K);
    int a[N][M];
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
        	scanf("%d", &a[i][j]);
    	}
    }
    if(M != 1 && N != 1){
    	for (int x0 = 0; x0 < N; x0++) {//左上 
			for (int y0 = 0; y0 < M; y0++) { //枚举中心点
				long long s = a[x0][y0];
				for (int r = 1; x0 - r >= 0 && y0 - r >= 0; r++) { //枚举延申长度
				int lb = y0 - r;
				int rb = y0; //计算当前行边界
				for (int y = lb; y <= rb; y++){
					//printf("左上%lld\n", s);
					s += a[x0 - r][y];
				} 
				if (s >= K) ans++;
				
				}
			}
		}
		for (int x0 = 0; x0 < N; x0++) {//右上 
			for (int y0 = 0; y0 < M; y0++) { //枚举中心点
				long long s = a[x0][y0];
				for (int r = 1; x0 - r >= 0 && y0 + r < M; r++) { //枚举延申长度
				int lb = y0;
				int rb = y0 + r; //计算当前行边界
				for (int y = lb; y <= rb; y++){
					//printf("右上%lld\n", s);
					s += a[x0 - r][y];
				} 
				if (s >= K) ans++;
				
				}
			}
		}
		for (int x0 = 0; x0 < N; x0++) {//左下 
			for (int y0 = 0; y0 < M; y0++) { //枚举中心点
				long long s = a[x0][y0];
				for (int r = 1; x0 + r < N && y0 - r >= 0; r++) { //枚举延申长度
				int lb = y0 - r;
				int rb = y0; //计算当前行边界
				for (int y = lb; y <= rb; y++){ 
					//printf("左下%lld\n", s);
					s += a[x0 + r][y];} 
				if (s >= K) ans++;
				
				}
			}
		}
		for (int x0 = 0; x0 < N; x0++) {//右下 
			for (int y0 = 0; y0 < M; y0++) { //枚举中心点
				long long s = a[x0][y0];
				for (int r = 1; x0 + r < N && y0 + r < M; r++) { //枚举延申长度
				int lb = y0;
				int rb = y0 + r; //计算当前行边界
				for (int y = lb; y <= rb; y++){ 
					//printf("右下%lld\n", s);
					s += a[x0 + r][y];
				} 
				if (s >= K) ans++;
				
				}
			}
		}
	}
	else{
		for(i=0;i<N;i++){
        	for(j=0;j<M;j++){
        		if(a[i][j] >= K)ans++;
    		}
    	}
	}
    	printf("%d", ans);
    	return 0;
}

		
	