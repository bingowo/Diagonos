#include <stdio.h>
int min(int a,int b){
	if(a<b) return a;
	else return b;
}
int main(){
	int n,m;
	scanf("%d %d",&m,&n);
	int a[201][201];
	int dp[201][201];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dp[0][0]=a[0][0];
	for(int i=0;i<n;i++){
		dp[i][0]=a[i][0]+dp[i-1][0];
	}
	for(int i=0;i<m;i++){
		dp[0][i]=a[0][i]+dp[0][i-1];
	}	
	/*for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/	
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			dp[i][j]=a[i][j]+min(dp[i-1][j],dp[i][j-1]);
		}
	}
	/*for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/	
	int x=m-1,y=n-1;
	printf("%d\n",dp[x][y]);
	int l=0;
	char road[20000];
	while(x>=0 && y>=0){
		int tmp=dp[x][y]-a[x][y];
		if(tmp==dp[x-1][y]){
			road[l]='D';
			x--;
		}
		else{
			road[l]='R';
			y--;
		}
		l++;
	}
	if(x>0){
		while(x){
			printf("D");
			x--;
		}
	}
	if(y>0){
		while(y){
			printf("R");
			y--;
		}
	}
	for(int i=l-2;i>=0;i--){
		printf("%c",road[i]);
	}
} 