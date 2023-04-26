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
		int i; 
		for(i = 0; i < 2; i ++){
			depth ++;
			if(d + step[i] > 0 && d + step[i] < n + 1){    //判断是否越界 
				travel(d + step[i]);
			}
			else depth --;
		}
	}
}
int main(void)
{
	int k;
	scanf("%d", &k);     //表示问题数 
	int i;
	for(i = 0 ; i < k; i ++){
		scanf("%d %d %d %d", &n, &p, &m, &t);
		memset(map, 0, sizeof(map));    //把map中元素给赋值 
		travel(p);
		printf("%d\n", map[t]);
	}
}