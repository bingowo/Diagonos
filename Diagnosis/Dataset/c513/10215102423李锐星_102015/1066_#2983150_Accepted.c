#include <stdio.h>

int cal(int n,int p,int m,int t)
{
	if(m==0&&p!=t) return 0;
	else if(m==0&&p==t)return 1;
	else if(m>0&&t==1) return cal(n,p,m-1,2);
	else if(m>0&&t==n) return cal(n,p,m-1,n-1);
	return cal(n,p,m-1,t-1)+cal(n,p,m-1,t+1);
}

void solve(int T)
{
	int n,p,m,t;
	scanf("%d%d%d%d",&n,&p,&m,&t);
	if(t>n){
		printf("0\n");
	}
	else {
		int way=cal(n,p,m,t);
		printf("%d\n",way);
	}
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