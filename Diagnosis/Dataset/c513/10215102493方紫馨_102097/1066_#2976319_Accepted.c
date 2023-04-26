#include<stdio.h>
#include<string.h>

int map[110];
int n,p,m,t;
int depth ;
void dfs(int d){
	//d表示现在人所处的楼栋数 	
	if(depth == m){
		//如果搜索结束也就是时间等于m为结束条件 
		map[d] ++;
		return ;
	}else{
		//搜索时间加一
		depth++;
		if(d-1>0){
			dfs(d-1);
		} 
		if(d+1<=n){
			dfs(d+1);
		} 
		depth--;	
	}
	
	
}

int main()
{
	int cas;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d%d%d",&n,&p,&m,&t);
		memset(map, 0, sizeof(map));
		depth = 0;
		dfs(p);
		printf("%d\n", map[t]);		
	}
	
	
	return 0;
}