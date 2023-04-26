#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n, isEqual = 1, a, b;
		int map[101][101] = {{0, 0}}, nmap[101] = {0};
		scanf("%d", &n);
		for(int j = 0 ; j < n ; j ++){
			scanf("%d %d", &a, &b);
			if(!map[a][b]){
				nmap[a] ++, nmap[b] ++;
				map[a][b] = 1;
			}
			if(nmap[a] > 1 || nmap[b] > 1){
				isEqual = 0;
			}
		}
		if(isEqual){
			printf("Lucky dxw!\n");
		}else{
			printf("Poor dxw!\n");
		}
	}
	
	return 0;
}