#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int num;
	char path[450];
	int sp;
}node;

int main()
{	
	int x,y;scanf("%d%d",&x,&y);
	node dp[x][y];
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			scanf("%d",&dp[i][j].num);
			dp[i][j].sp=0;
		}
	}
	for(int j=1;j<y;j++){
		int t=dp[0][j].num;
		dp[0][j]=dp[0][j-1];
		dp[0][j].num+=t;
		dp[0][j].path[dp[0][j].sp++]='R';
	}
	for(int i=1;i<x;i++){
		int t=dp[i][0].num;
		dp[i][0]=dp[i-1][0];
		dp[i][0].num+=t;
		dp[i][0].path[dp[i][0].sp++]='D';
	}
	for(int i=1;i<x;i++){
		for(int j=1;j<y;j++){
			char tag=dp[i-1][j].num<dp[i][j-1].num?'D':'R';
			int tmp=dp[i][j].num;
			dp[i][j]=(tag=='D'?dp[i-1][j]:dp[i][j-1]);
			dp[i][j].num+=tmp;
			dp[i][j].path[dp[i][j].sp++]=tag;
		}
	}
	dp[x-1][y-1].path[dp[x-1][y-1].sp]=0;
	printf("%d\n%s",dp[x-1][y-1].num,dp[x-1][y-1].path);
	return 0;
}