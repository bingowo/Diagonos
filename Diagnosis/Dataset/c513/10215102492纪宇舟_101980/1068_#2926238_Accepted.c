#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
long long f[32][32];
long long dfs(int n,int m)
{
	if(n<m)return 0;
	if(n==m)return 1;
	if(f[n][m]==0)f[n][m]=2*dfs(n-1,m)+(1LL<<(n-m-1))-dfs(n-m-1,m);//¿¼ÂÇ´Ó³¤¶Èn-1µÄµÝÍÆ 
	return f[n][m];
}
int main()
{
	int n,m;
	memset(f,0,sizeof(f));
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==-1&&m==-1)break;
		printf("%lld\n",dfs(n,m));
	}
	return 0;
} 