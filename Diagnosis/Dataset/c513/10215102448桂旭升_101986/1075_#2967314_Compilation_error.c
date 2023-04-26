#include<stdio.h>
#include<math.h>
int maxn = 201;                      //行列最大值
int M,N,K=0;                                //M行N列，路径有K个结点
int D[maxn][maxn];                          //存储原始矩阵值
int b[2][maxn] = {0};
int f(int i, int j, int a){
	int k, temp1, temp2;int dp = 0; 
	if(i == M-1){
		for(k = j; k <= N-1; k++){
			dp += D[M-1][k];
		}
		return dp;
	}
	else if(j == N-1){
		for(k = i; k <= M-1; k++){
			dp += D[k][N-1];
		}
		return dp;
	}
	else{
		dp = D[i][j];//printf("%d %d %d\n",i, j, dp);
		temp1 = f(i+1, j, a+1); temp2 = f(i, j+1, a+1);
		if(temp1 > temp2){
			b[0][a] = i; b[1][a] = j;
			dp += temp2;
			if(j+1 == N-1){
				b[0][a+1] = i; b[1][a+1] = j+1;
			}
			return dp;
		}
		else{
			b[0][a] = i; b[1][a] = j;
			dp += temp1;
			if(i+1 == M-1){
				b[0][a+1] = i+1; b[1][a+1] = j;
			}
			return dp;
		}
		
	}
} 
int main(){
	int i;
    scanf("%d%d", &M, &N);
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &D[i][j]);
    printf("%d\n", f(0, 0, 0));
    for(i = 0; i < N+M-2; i++){
    	if(b[0][i] != M-1 && b[1][i] != N-1){//printf("q%d\n", b[1][2]);
    		if(b[0][i] < b[0][i+1])printf("D");
    		if(b[1][i] < b[1][i+1])printf("R");
		}
		else if(b[0][i] == M-1){
			for(; i < M+N-2; i++)printf("R");
		}
		else if(b[1][i] == N-1){
			for(; i < M+N-2; i++)printf("D");
		}
		
	}
    return 0;
}