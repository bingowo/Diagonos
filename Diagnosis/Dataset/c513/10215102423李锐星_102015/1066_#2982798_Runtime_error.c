#include <stdio.h>
#include <math.h>

int sum(int n,int p,int m,int t)
{
	if(m<=0){
		return 0;
	}
	else{
		if(p==1){
			return sum(n,2,m-1,t);
		}
		else if(p==n){
			return sum(n,p-1,m-1,t);
		}
		return sum(n,p-1,m-1,t)+sum(n,p+1,m-1,t);
	}
}

void solve(int T)
{
	int n,p,m,t;
	scanf("%d%d%d%d",n,p,m,t);
	printf("%d\n",sum(n,p,m,t));
}


int main()
{
	int cas;
	scanf("%d",&cas);
	for (int i=0;i<cas;i++){
		solve(i);
	}
	return 0;
}