/*
Created by Shizumu on 2022-03-14
	比较简单的dfs，前提是要知道什么是dfs。 
*/ 
#include <stdio.h>
#include <string.h>

int map[110];
int n, p, m, t;
//规定走的方向 
int step[2] = {-1, 1};

void travel(int d)
{
	static int depth = 0;
	if(depth == m){
		//如果走到目标点就在该结果+1 
		map[d] ++;
		return ;
	}else{
		//遍历步数 
		for(int i = 0; i < 2; i ++){
			depth ++;
			if(d + step[i] > 0 && d + step[i] < n + 1){
				travel(d + step[i]);
			}
			depth --;
		}
	}
}

int main(void)
{
	int k;
	scanf("%d", &k);
	for(int i = 0 ; i < k; i ++){
		scanf("%d %d %d %d", &n, &p, &m, &t);
		memset(map, 0, sizeof(map));
		travel(p);
		printf("%d\n", map[t]);
	}
}
