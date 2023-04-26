#include<iostream>
using namespace std;
const int maxn = 1001;                      //行列最大值
int M,N,K=0;                                //M行N列，路径有K个结点
int D[maxn][maxn];                          //存储原始矩阵值
int dp[maxn][maxn];                         //从D[0][0]到D[i][j]路径最小值
int mp[maxn];                               //保存路径中的结点值
int main(){
	int k;
    scanf("%d%d", &M, &N);
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &D[i][j]);
    dp[0][0]=D[0][0];
    for(int i=1; i<M; i++)
        dp[i][0] = dp[i-1][0]+ D[i][0];     //对于第一列的点D[i][0]，只可能是从上面的点D[i-1][0]往下走
    for(int j=1; j<N; j++)
        dp[0][j] = dp[0][j-1]+ D[0][j];     //对于第一行的点D[0][j]，只可能是从左边的点D[0][j-1]往右走
    for(int i=1; i<M; i++)
        for(int j=1; j<N; j++)              //点D[i][j]，是从D[i][j-1]和D[i-1][j]较小的而来
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + D[i][j];
    int i=M-1,j=N-1;
    mp[K++]=D[i][j];
    while(i>=0 && j>=0){                    //倒着找路径上的点
        if(i==0 && j==0){
            break;
        } else if(i==0){                    //在第一行上，那么上一个点只能是左边的点
            mp[K++]=D[i][j-1];
            j--;
        } else if(j==0){                    //在第一列上，那么上一个点只能是上面的点
            mp[K++]=D[i-1][j];
            i--;
        } else {                            //否则就找左边和上面的dp最小对应的那个点D
            if(dp[i-1][j]<dp[i][j-1]){
                mp[K++]=D[i-1][j];
                i--;
            } else {
                mp[K++]=D[i][j-1];
                j--;
            }
        }
    }
    printf("%d\n", dp[M-1][N-1]);k = 0; j = 0;
    for(int i=K-2;i>=0;i--){
        while(k < M && j < N){
        	if(mp[i] == D[k+1][j]){
        		printf("D"); k++;
			}
        	if(mp[i] == D[k][j+1]){
        		printf("R"); j++;
			}
			break;
		}
    }
    return 0;
}