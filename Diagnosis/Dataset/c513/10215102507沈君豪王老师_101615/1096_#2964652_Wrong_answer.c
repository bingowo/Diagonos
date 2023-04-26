#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n, isEqual = 1, n1, n2;
		int map[100001] = {0};
		scanf("%d", &n);
		for(int j = 0 ; j < n ; j ++){
			scanf("%d %d", &n1, &n2);
			map[n1]++, map[n2] ++;
			if(map[n1] > 1 || map[n2] > 1){
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