#include <stdio.h>
#include <math.h>

typedef struct{
	int x, y;
}Point;

int reach(int axy, int mapxy, int offsetxy)
{
	int ret;
	if(offsetxy > 0 && axy >= mapxy && (axy - mapxy) % offsetxy == 0){
		ret = (axy - mapxy) / offsetxy + 1;
	}else if(offsetxy < 0 && axy <= mapxy && (axy - mapxy) % offsetxy == 0){
		ret = (axy - mapxy) / offsetxy + 1;
	}else if(offsetxy == 0 && axy == mapxy){
		ret = 0;
	}else{
		ret = -1;
	}
	
	return ret;
}

int main(void)
{
	char order[110];
	scanf("%s", order);
	char *p = order;
	Point o = {0, 0}, offset = {0, 0};
	int t, mapx[101], mapy[101];
	while(*p){
		mapx[(p - order)] = o.x, mapy[(p - order)] = o.y;
		switch(*p){
			case 'U': o.y++; break;
			case 'D': o.y--; break;
			case 'L': o.x--; break;
			case 'R': o.x++; break;
		}
		p ++;
	}
	mapx[(p - order)] = o.x, mapy[(p - order)] = o.y;
	offset = o;
	scanf("%d", &t);
	int x, y, isReachx = -1, isReachy = -1, len = p - order;
	for(int i = 0 ; i < t; i ++){
		scanf("%d %d", &x, &y);
		for(int j = 0 ; j < len ; j ++){
			isReachx = -1, isReachy = -1;
			isReachx = reach(x, mapx[j], offset.x);
			isReachy = reach(y, mapy[j], offset.y);
			if((isReachx != -1 && isReachy != -1) && (isReachx * isReachy == 0 || isReachx == isReachy)){
				break;
			}
		}
		if((isReachx != -1 && isReachy != -1) && (isReachx * isReachy == 0 || isReachx == isReachy)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	return 0;
}