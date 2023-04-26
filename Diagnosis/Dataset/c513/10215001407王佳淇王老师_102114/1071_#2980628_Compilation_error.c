#include<stdio.h>
#define M 10000
#define N 10007
 long long  int dp[M][M]={1};
  
long long int work(int n,int m,int a, int b)
{  
    int i,j; 
   for (i=0;i<=n;i++) 
    for (j=0;j<=m;j++)
     if (i+j){
       if (i==0) 
           dp[i][j] = b*dp[i][j-1]%N;
       else if (j==0) 
           dp[i][j] = a*dp[i-1][j]%N;
       else 
           dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;}
    return dp[n][m];

}

int main(){
	   int T;
	  scanf("%d",&T);
	for(int v=0;v<T;v++){
	    	int  a,b,k,n,m;
		scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
		printf("case #%d:\n",v);
		long long int ans =work(n,m,a,b);
		printf("%lld\n",ans);
	}
	return 0;
}