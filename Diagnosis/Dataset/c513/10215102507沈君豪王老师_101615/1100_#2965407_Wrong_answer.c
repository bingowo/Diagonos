#include <stdio.h>
#include <math.h>

typedef struct{
	int x, y;
}Point;

int UnsignedPoint(int n){ return n < 0 ? 201 + n : n;}

int main(void)
{
	char order[110];
	scanf("%s", order);
	char *p = order;
	Point o = {0, 0}, min = {0, 0}, max = {0, 0}, offset = {0, 0};
	int map[201][201] = {0}, t;
	while(*p){
		map[UnsignedPoint(o.x)][UnsignedPoint(o.y)] = 1;
		switch(*p){
			case 'U': o.y++; break;
			case 'D': o.y--; break;
			case 'L': o.x--; break;
			case 'R': o.x++; break;
		}
		if(o.x < min.x){min.x = o.x;}
		if(o.y < min.y){min.y = o.y;}
		if(o.x > max.x){max.x = o.x;}
		if(o.y > max.y){max.y = o.y;}
		p ++;
	}
	map[UnsignedPoint(o.x)][UnsignedPoint(o.y)] = 1;
	offset = o;
	scanf("%d", &t);
	int x, y, tx, ty, mx, my, isReach = 0;
	for(int i = 0 ; i < t; i ++){
		scanf("%d %d", &x, &y);
		isReach = 0;
		if(!map[UnsignedPoint(x)][UnsignedPoint(y)]){
			if(x * offset.x >= 0 && y * offset.y >= 0){
				mx = abs(offset.x == 0 ? 0 : x / offset.x);
				my = abs(offset.y == 0 ? 0 : y / offset.y);
				tx = x - (mx > my ? mx : my) * offset.x;
				ty = y - (mx > my ? mx : my) * offset.y;
				while((tx >= min.x && ty >= min.y) && (tx <= max.x && ty <= max.y)){
					if(map[UnsignedPoint(tx)][UnsignedPoint(ty)]){
						isReach = 1;
						break;
					}
					tx += offset.x, ty += offset.y;
				}
				mx = abs(offset.x == 0 ? 0 : x / offset.x);
				my = abs(offset.y == 0 ? 0 : y / offset.y);
				tx = x - (mx > my ? my : mx) * offset.x;
				ty = y - (mx > my ? my : mx) * offset.y;
				while((tx >= min.x && ty >= min.y) && (tx <= max.x && ty <= max.y)){
					if(map[UnsignedPoint(tx)][UnsignedPoint(ty)]){
						isReach = 1;
						break;
					}
					tx -= offset.x, ty -= offset.y;
				}				
			}else{
				isReach = 0;
			}
		}else{
			isReach = 1;
		}
		if(isReach){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	return 0;
}