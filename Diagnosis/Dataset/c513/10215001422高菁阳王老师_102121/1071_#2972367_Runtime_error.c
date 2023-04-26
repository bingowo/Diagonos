#include <stdio.h>
#include <stdlib.h>
#define N 10007
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int f(int n,int m,int a,int b){
	int dp[1000000][1000000]={1},i,j;
	for(i=0;i<n;i++)
	for(j=0;j<m;j++){
		if(i+j){
		if(i==0)
		dp[i][j] = b*dp[i][j-1]%N;
       else if (j==0) 
           dp[i][j] = a*dp[i-1][j]%N;
       else 
           dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;
    }
    }return dp[n][m];
	
}
int main(int argc, char *argv[]) {
	int n,k,a,b,m,n1,k1,f1;
	scanf("%d",&n1);
	for(k1=0;k1<n1;k1++){
		scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
		printf("case #%d:\n",k1);
		f1=f(n,m,a,b);
		printf("%d\n",f1);
	}
	return 0;
}